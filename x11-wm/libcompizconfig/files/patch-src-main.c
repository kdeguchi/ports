--- src/main.c.orig	2018-12-12 13:00:51 UTC
+++ src/main.c
@@ -627,7 +627,8 @@ openBackend (char *backend)
 	if (dlname != NULL)
 	{
 	    dlerror ();
-	    dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_LOCAL);
+	    dlhand = dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
+	    dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
 	    err = dlerror ();
             free (dlname);
 	}
@@ -639,7 +640,8 @@ openBackend (char *backend)
 	                              LIBDIR, backend);
 	if (dlname != NULL)
 	{
-	    dlhand = dlopen (dlname, RTLD_NOW | RTLD_NODELETE | RTLD_LOCAL);
+	    dlhand = dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
+	    dlopen (dlname, RTLD_NOW | RTLD_LOCAL);
 	    err = dlerror ();
 	    free (dlname);
 	}
