--- panel-plugin/weather-parsers.c.orig	2020-02-23 00:39:53 UTC
+++ panel-plugin/weather-parsers.c
@@ -445,28 +445,28 @@ parse_astro_time(xmlNode *cur_node)
         if (child_node->type == XML_ELEMENT_NODE) {
             if (NODE_IS_TYPE(child_node, "sunrise")) {
                 sunrise = remove_timezone_offset(PROP(child_node, "time"));
-                astro->sunrise = parse_timestring(sunrise, NULL, FALSE);
+                astro->sunrise = parse_timestring(sunrise, NULL, TRUE);
                 xmlFree(sunrise);
                 sun_rises = TRUE;
             }
 
             if (NODE_IS_TYPE(child_node, "moonset")) {
                 moonset = remove_timezone_offset(PROP(child_node, "time"));
-                astro->moonset = parse_timestring(moonset, NULL, FALSE);
+                astro->moonset = parse_timestring(moonset, NULL, TRUE);
                 xmlFree(moonset);
                 moon_sets = TRUE;
             }
 
             if (NODE_IS_TYPE(child_node, "sunset")) {
                 sunset = remove_timezone_offset(PROP(child_node, "time"));
-                astro->sunset = parse_timestring(sunset, NULL, FALSE);
+                astro->sunset = parse_timestring(sunset, NULL, TRUE);
                 xmlFree(sunset);
                 sun_sets = TRUE;
             }
 
             if (NODE_IS_TYPE(child_node, "moonrise")) {
                 moonrise = remove_timezone_offset(PROP(child_node, "time"));
-                astro->moonrise = parse_timestring(moonrise, NULL, FALSE);
+                astro->moonrise = parse_timestring(moonrise, NULL, TRUE);
                 xmlFree(moonrise);
                 moon_rises = TRUE;
             }
