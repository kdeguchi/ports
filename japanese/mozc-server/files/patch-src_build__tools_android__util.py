--- src/build_tools/android_util.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_tools/android_util.py
@@ -548,7 +548,7 @@ def GetAvailableEmulatorPorts(android_home):
   (devices_result, _) = process.communicate()
   used_ports = set(int(port) for port
                    in re.findall(r'emulator-(\d+)', devices_result))
-  return [port for port in xrange(5554, 5586, 2) if port not in used_ports]
+  return [port for port in range(5554, 5586, 2) if port not in used_ports]
 
 
 def SetUpTestingSdkHomeDirectory(dest_android_sdk_home,
@@ -575,7 +575,7 @@ def SetUpTestingSdkHomeDirectory(dest_android_sdk_home
           'create', 'avd',
           '--force',
           '--sdcard', '512M',]
-  for key, value in options.iteritems():
+  for key, value in options.items():
     args.extend([key, value])
   env = {'ANDROID_SDK_HOME': os.path.abspath(dest_android_sdk_home)}
   logging.info('Creating AVD: %s', args)
@@ -615,7 +615,7 @@ def GetAvdProperties(android_sdk_home, avd_name, my_op
 def main():
   for arg in sys.argv[1:]:
     for item in sorted(GetApkProperties(arg).items()):
-      print '%s: %s' % item
+      print('%s: %s' % item)
 
 
 if __name__ == '__main__':
