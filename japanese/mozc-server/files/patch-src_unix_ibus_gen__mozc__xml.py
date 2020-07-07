--- src/unix/ibus/gen_mozc_xml.py.orig	2019-03-04 18:35:55 UTC
+++ src/unix/ibus/gen_mozc_xml.py
@@ -74,7 +74,7 @@ CPP_FOOTER = """}  // namespace
 
 
 def OutputXmlElement(param_dict, element_name, value):
-  print '  <%s>%s</%s>' % (element_name, (value % param_dict), element_name)
+  print('  <%s>%s</%s>' % (element_name, (value % param_dict), element_name))
 
 
 def OutputXml(param_dict, component, engine_common, engines, setup_arg):
@@ -90,27 +90,27 @@ def OutputXml(param_dict, component, engine_common, en
     engines: A dictionary from a property name to a list of property values of
         engines. For example, {'name': ['mozc-jp', 'mozc', 'mozc-dv']}.
   """
-  print '<?xml version="1.0" encoding="utf-8"?>'
-  print '<component>'
+  print('<?xml version="1.0" encoding="utf-8"?>')
+  print('<component>')
   for key in component:
     OutputXmlElement(param_dict, key, component[key])
-  print '<engines>'
+  print('<engines>')
   for i in range(len(engines['name'])):
-    print '<engine>'
+    print('<engine>')
     for key in engine_common:
       OutputXmlElement(param_dict, key, engine_common[key])
     if setup_arg:
       OutputXmlElement(param_dict, 'setup', ' '.join(setup_arg))
     for key in engines:
       OutputXmlElement(param_dict, key, engines[key][i])
-    print '</engine>'
-  print '</engines>'
-  print '</component>'
+    print('</engine>')
+  print('</engines>')
+  print('</component>')
 
 
 def OutputCppVariable(param_dict, prefix, variable_name, value):
-  print 'const char k%s%s[] = "%s";' % (prefix, variable_name.capitalize(),
-                                        (value % param_dict))
+  print('const char k%s%s[] = "%s";' % (prefix, variable_name.capitalize(),
+                                        (value % param_dict)))
 
 
 def OutputCpp(param_dict, component, engine_common, engines):
@@ -123,18 +123,18 @@ def OutputCpp(param_dict, component, engine_common, en
     engines: ditto.
   """
   guard_name = 'MOZC_UNIX_IBUS_MAIN_H_'
-  print CPP_HEADER % (guard_name, guard_name)
+  print(CPP_HEADER % (guard_name, guard_name))
   for key in component:
     OutputCppVariable(param_dict, 'Component', key, component[key])
   for key in engine_common:
     OutputCppVariable(param_dict, 'Engine', key, engine_common[key])
   for key in engines:
-    print 'const char* kEngine%sArray[] = {' % key.capitalize()
+    print('const char* kEngine%sArray[] = {' % key.capitalize())
     for i in range(len(engines[key])):
-      print '"%s",' % (engines[key][i] % param_dict)
-    print '};'
-  print 'const size_t kEngineArrayLen = %s;' % len(engines['name'])
-  print CPP_FOOTER % guard_name
+      print('"%s",' % (engines[key][i] % param_dict))
+    print('};')
+  print('const size_t kEngineArrayLen = %s;' % len(engines['name']))
+  print(CPP_FOOTER % guard_name)
 
 
 def CheckIBusVersion(options, minimum_version):
