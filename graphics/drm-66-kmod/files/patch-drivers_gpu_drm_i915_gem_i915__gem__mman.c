--- drivers/gpu/drm/i915/gem/i915_gem_mman.c.orig	2025-03-13 08:41:21 UTC
+++ drivers/gpu/drm/i915/gem/i915_gem_mman.c
@@ -34,6 +34,7 @@
 #include <vm/vm_object.h>
 #include <vm/vm_pager.h>
 #include <vm/vm_param.h>
+#include <vm/vm_radix.h>
 #endif
 
 #ifdef __linux__ /* Mute unused function warning. */
@@ -168,7 +169,14 @@ i915_gem_mmap_ioctl(struct drm_device *dev, void *data
 	if ((rv == KERN_SUCCESS) && (args->flags & I915_MMAP_WC)) {
 		VM_OBJECT_WLOCK(vmobj);
 		if (vm_object_set_memattr(vmobj, VM_MEMATTR_WRITE_COMBINING) != KERN_SUCCESS) {
-			for (vm_page_t page = vm_page_find_least(vmobj, 0); page != NULL; page = vm_page_next(page)) {
+#if __FreeBSD_version >= 1500038
+			struct pctrie_iter pages;
+			vm_page_t page;
+			vm_page_iter_init(&pages, vmobj);
+			VM_RADIX_FORALL(page, &pages)
+#else
+			for (vm_page_t page = vm_page_find_least(vmobj, 0); page != NULL; page = vm_page_next(page))
+#endif
 				pmap_page_set_memattr(page, VM_MEMATTR_WRITE_COMBINING);
 			}
 		}
