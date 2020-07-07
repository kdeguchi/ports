--- panel-plugin/weather.c.orig	2020-02-23 00:39:53 UTC
+++ panel-plugin/weather.c
@@ -656,7 +656,7 @@ update_handler(plugin_data *data)
         /* build url */
         url = g_strdup_printf("https://api.met.no"
                               "/weatherapi/locationforecast/%s/"
-                              "?lat=%s&lon=%s&msl=%d",
+                              "classic?lat=%s&lon=%s&altitude=%d",
                               api_version,
                               data->lat, data->lon, data->msl);
 
@@ -1115,8 +1115,8 @@ write_cache_file(plugin_data *data)
             if (G_UNLIKELY(astro == NULL))
                 continue;
             value = format_date(astro->day, "%Y-%m-%d", TRUE);
-            start = format_date(astro->sunrise, date_format, FALSE);
-            end = format_date(astro->sunset, date_format, FALSE);
+            start = format_date(astro->sunrise, date_format, TRUE);
+            end = format_date(astro->sunset, date_format, TRUE);
             g_string_append_printf(out, "[astrodata%d]\n", i);
             CACHE_APPEND("day=%s\n", value);
             CACHE_APPEND("sunrise=%s\n", start);
@@ -1129,8 +1129,8 @@ write_cache_file(plugin_data *data)
             g_free(start);
             g_free(end);
 
-            start = format_date(astro->moonrise, date_format, FALSE);
-            end = format_date(astro->moonset, date_format, FALSE);
+            start = format_date(astro->moonrise, date_format, TRUE);
+            end = format_date(astro->moonset, date_format, TRUE);
             CACHE_APPEND("moonrise=%s\n", start);
             CACHE_APPEND("moonset=%s\n", end);
             CACHE_APPEND("moon_never_rises=%s\n",
@@ -1303,10 +1303,10 @@ read_cache_file(plugin_data *data)
         astro->day = parse_timestring(timestring, "%Y-%m-%d", TRUE);
         g_free(timestring);
         CACHE_READ_STRING(timestring, "sunrise");
-        astro->sunrise = parse_timestring(timestring, NULL, FALSE);
+        astro->sunrise = parse_timestring(timestring, NULL, TRUE);
         g_free(timestring);
         CACHE_READ_STRING(timestring, "sunset");
-        astro->sunset = parse_timestring(timestring, NULL, FALSE);
+        astro->sunset = parse_timestring(timestring, NULL, TRUE);
         g_free(timestring);
         astro->sun_never_rises =
             g_key_file_get_boolean(keyfile, group, "sun_never_rises", NULL);
@@ -1314,10 +1314,10 @@ read_cache_file(plugin_data *data)
             g_key_file_get_boolean(keyfile, group, "sun_never_sets", NULL);
 
         CACHE_READ_STRING(timestring, "moonrise");
-        astro->moonrise = parse_timestring(timestring, NULL, FALSE);
+        astro->moonrise = parse_timestring(timestring, NULL, TRUE);
         g_free(timestring);
         CACHE_READ_STRING(timestring, "moonset");
-        astro->moonset = parse_timestring(timestring, NULL, FALSE);
+        astro->moonset = parse_timestring(timestring, NULL, TRUE);
         g_free(timestring);
         CACHE_READ_STRING(astro->moon_phase, "moon_phase");
         astro->moon_never_rises =
@@ -1731,9 +1731,9 @@ weather_get_tooltip_text(const plugin_data *data)
             sunval = g_strdup(_("The sun never sets today."));
         } else {
             sunrise = format_date(data->current_astro->sunrise,
-                                  "%H:%M:%S", FALSE);
+                                  "%H:%M:%S", TRUE);
             sunset = format_date(data->current_astro->sunset,
-                                 "%H:%M:%S", FALSE);
+                                 "%H:%M:%S", TRUE);
             sunval =
                 g_strdup_printf(_("The sun rises at %s and sets at %s."),
                                 sunrise, sunset);
