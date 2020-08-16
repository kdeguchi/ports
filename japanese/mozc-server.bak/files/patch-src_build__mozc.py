--- src/build_mozc.py.orig	2019-03-04 18:35:55 UTC
+++ src/build_mozc.py
@@ -979,7 +979,7 @@ def RunTests(target_platform, configuration, parallel_
       logging.info('running %s...', binary)
       try:
         test_function(binary, gtest_report_dir, options)
-      except RunOrDieError, e:
+      except RunOrDieError as e:
         logging.error(e)
         failed_tests.append(binary)
   else:
@@ -1118,7 +1118,7 @@ def RunTestsMain(options, args):
   # and '-c' and 'Release' are build options.
   targets = []
   build_options = []
-  for i in xrange(len(args)):
+  for i in range(len(args)):
     if args[i].startswith('-'):
       # starting with build options
       build_options = args[i:]
@@ -1135,7 +1135,7 @@ def RunTestsMain(options, args):
 
   # configuration flags are shared among runtests options and
   # build options.
-  if 'jobs' in vars(options).keys():
+  if 'jobs' in list(vars(options).keys()):
     build_options.extend(['-j', options.jobs])
   if options.configuration:
     build_options.extend(['-c', options.configuration])
@@ -1226,14 +1226,14 @@ def CleanMain(options, unused_args):
 
 def ShowHelpAndExit():
   """Shows the help message."""
-  print 'Usage: build_mozc.py COMMAND [ARGS]'
-  print 'Commands: '
-  print '  gyp          Generate project files.'
-  print '  build        Build the specified target.'
-  print '  runtests     Build all tests and run them.'
-  print '  clean        Clean all the build files and directories.'
-  print ''
-  print 'See also the comment in the script for typical usage.'
+  print('Usage: build_mozc.py COMMAND [ARGS]')
+  print('Commands: ')
+  print('  gyp          Generate project files.')
+  print('  build        Build the specified target.')
+  print('  runtests     Build all tests and run them.')
+  print('  clean        Clean all the build files and directories.')
+  print('')
+  print('See also the comment in the script for typical usage.')
   sys.exit(1)
 
 
