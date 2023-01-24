--- src/build_tools/util.py.orig	2022-07-23 14:02:59 UTC
+++ src/build_tools/util.py
@@ -53,7 +53,7 @@ def IsMac():
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def GetNumberOfProcessors():
