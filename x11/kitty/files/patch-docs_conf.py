--- docs/conf.py.orig	2026-11-23 09:02:42 UTC
+++ docs/conf.py
@@ -230,16 +230,8 @@ def commit_role(
         return subprocess.check_output(('git',) + args, cwd=kitty_src, stderr=subprocess.DEVNULL).decode('utf-8').strip()
 
     text = text.strip()
-    if os.path.exists(os.path.join(kitty_src, '.git')):
-        try:
-            commit_id = git('rev-list', '--max-count=1', text)
-            short_id = git('rev-list', '--max-count=1', '--abbrev-commit', commit_id)
-        except FileNotFoundError:
-            commit_id = short_id = ''  # git is not installed
-        except subprocess.CalledProcessError:
-            return error(f'git commit id "{text}" not recognized.')
-    else:
-        commit_id = short_id = ''  # no git history, for example, when building from a source archive
+    commit_id = text
+    short_id = text[:9]
     if not commit_id:
         # Without git history we cannot resolve the commit, so link to it
         # using the id as written, GitHub resolves abbreviated commit ids.
