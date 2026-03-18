--- src/ck-sysdeps-unix.c.orig	2025-03-20 16:35:45 UTC
+++ src/ck-sysdeps-unix.c
@@ -394,44 +394,44 @@ static gchar *
 
 /* Call g_free on string when done using it. [transfer: full] */
 static gchar *
-get_rundir (guint uid)
+get_rundir (const gchar *name)
 {
         const gchar *base;
 
         TRACE ();
 
-        base = RUNDIR "/user";
+        base = RUNDIR "/xdg";
 
-        return g_strdup_printf ("%s/%d", base, uid);
+        return g_strdup_printf ("%s/%s", base, name);
 }
 
-static gboolean
+/*static gboolean
 create_rundir_base (guint uid)
 {
         const gchar *base;
 
         TRACE ();
 
-        base = RUNDIR "/user";
+        base = RUNDIR "/xdg";*/
 
         /* Create the base directory that we will own. */
-        if (g_mkdir_with_parents (base, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) != 0) {
+        /*if (g_mkdir_with_parents (base, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) != 0) {
                 g_warning ("Failed to create %s, reason was: %s", base, strerror(errno));
                 errno = 0;
                 return FALSE;
-        }
+        }*/
 
         /* ensure we have ownership */
-        if (chown (base, 0, 0) != 0) {
+        /*if (chown (base, 0, 0) != 0) {
                 g_warning ("Failed to chown %s, reason was: %s", base, strerror(errno));
                 errno = 0;
                 return FALSE;
         }
 
         return TRUE;
-}
+}*/
 
-static gboolean
+/*static gboolean
 remove_rundir (guint uid, const gchar *dest)
 {
         gchar   *command;
@@ -458,7 +458,7 @@ remove_rundir (guint uid, const gchar *dest)
         }
 
         return TRUE;
-}
+}*/
 
 gchar *
 ck_generate_runtime_dir_for_user (guint uid)
@@ -477,37 +477,37 @@ ck_generate_runtime_dir_for_user (guint uid)
         }
 
         /* ensure we have created the base directory */
-        if (create_rundir_base (uid) == FALSE) {
+        /*if (create_rundir_base (uid) == FALSE) {
                 return NULL;
-        }
+        }*/
 
-        dest = get_rundir (uid);
+        dest = get_rundir (pwent->pw_name);
 
         /* Ensure any files from the last session are removed */
-        if (g_file_test (dest, G_FILE_TEST_EXISTS) == TRUE) {
+        /*if (g_file_test (dest, G_FILE_TEST_EXISTS) == TRUE) {
                 remove_rundir (uid, dest);
-        }
+        }*/
 
         /* Create the new directory */
-        if (g_mkdir_with_parents (dest, S_IRWXU) != 0) {
+        /*if (g_mkdir_with_parents (dest, S_IRWXU) != 0) {
                 g_warning ("Failed to create XDG_RUNTIME_DIR, reason was: %s", strerror(errno));
                 errno = 0;
                 g_free (dest);
                 return NULL;
-        }
+        }*/
 
-        g_debug ("setting uid %d, gid %d", uid, pwent->pw_gid);
+        //g_debug ("setting uid %d, gid %d", uid, pwent->pw_gid);
 
         /* assign ownership to the user */
-        if (chown (dest, uid, pwent->pw_gid) != 0) {
+        /*if (chown (dest, uid, pwent->pw_gid) != 0) {
                 g_warning ("Failed to chown XDG_RUNTIME_DIR, reason was: %s", strerror(errno));
                 errno = 0;
                 g_free (dest);
                 return NULL;
-        }
+        }*/
 
         /* attempt to make it a small tmpfs location */
-        ck_make_tmpfs (uid, pwent->pw_gid, dest);
+        //ck_make_tmpfs (uid, pwent->pw_gid, dest);
 
         return dest;
 }
@@ -515,20 +515,20 @@ ck_remove_runtime_dir_for_user (guint uid)
 gboolean
 ck_remove_runtime_dir_for_user (guint uid)
 {
-        gchar        *dest;
+        //gchar        *dest;
 
         TRACE ();
 
-        dest = get_rundir (uid);
+        //dest = get_rundir (uid);
 
         /* attempt to remove the tmpfs */
-        ck_remove_tmpfs (uid, dest);
+        //ck_remove_tmpfs (uid, dest);
 
         /* remove the user's runtime dir now that all user sessions
          * are gone */
-        remove_rundir (uid, dest);
+        //remove_rundir (uid, dest);
 
-        g_free (dest);
+        //g_free (dest);
 
         return TRUE;
 }
