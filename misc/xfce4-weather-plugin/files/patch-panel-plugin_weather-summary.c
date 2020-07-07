--- panel-plugin/weather-summary.c.orig	2020-02-23 00:39:53 UTC
+++ panel-plugin/weather-summary.c
@@ -417,12 +417,12 @@ create_summary_tab(plugin_data *data)
             value = g_strdup(_("\tSunset:\t\tThe sun never sets today.\n"));
             APPEND_TEXT_ITEM_REAL(value);
         } else {
-            sunrise = format_date(data->current_astro->sunrise, NULL, FALSE);
+            sunrise = format_date(data->current_astro->sunrise, NULL, TRUE);
             value = g_strdup_printf(_("\tSunrise:\t\t%s\n"), sunrise);
             g_free(sunrise);
             APPEND_TEXT_ITEM_REAL(value);
 
-            sunset = format_date(data->current_astro->sunset, NULL, FALSE);
+            sunset = format_date(data->current_astro->sunset, NULL, TRUE);
             value = g_strdup_printf(_("\tSunset:\t\t%s\n\n"), sunset);
             g_free(sunset);
             APPEND_TEXT_ITEM_REAL(value);
@@ -445,12 +445,12 @@ create_summary_tab(plugin_data *data)
                 g_strdup(_("\tMoonset:\tThe moon never sets today.\n"));
             APPEND_TEXT_ITEM_REAL(value);
         } else {
-            moonrise = format_date(data->current_astro->moonrise, NULL, FALSE);
+            moonrise = format_date(data->current_astro->moonrise, NULL, TRUE);
             value = g_strdup_printf(_("\tMoonrise:\t%s\n"), moonrise);
             g_free(moonrise);
             APPEND_TEXT_ITEM_REAL(value);
 
-            moonset = format_date(data->current_astro->moonset, NULL, FALSE);
+            moonset = format_date(data->current_astro->moonset, NULL, TRUE);
             value = g_strdup_printf(_("\tMoonset:\t%s\n"), moonset);
             g_free(moonset);
             APPEND_TEXT_ITEM_REAL(value);
@@ -699,13 +699,13 @@ forecast_day_header_tooltip_text(xml_astro *astro)
                                     "Sunset: The sun never sets this day."
                                     "</small></tt>\n"));
         else {
-            sunrise = format_date(astro->sunrise, NULL, FALSE);
+            sunrise = format_date(astro->sunrise, NULL, TRUE);
             g_string_append_printf(text, _("<tt><small>"
                                            "Sunrise: %s"
                                            "</small></tt>\n"), sunrise);
             g_free(sunrise);
 
-            sunset = format_date(astro->sunset, NULL, FALSE);
+            sunset = format_date(astro->sunset, NULL, TRUE);
             g_string_append_printf(text, _("<tt><small>"
                                            "Sunset:  %s"
                                            "</small></tt>\n\n"), sunset);
@@ -732,13 +732,13 @@ forecast_day_header_tooltip_text(xml_astro *astro)
                               "Moonset: The moon never sets this day."
                               "</small></tt>\n"));
         else {
-            moonrise = format_date(astro->moonrise, NULL, FALSE);
+            moonrise = format_date(astro->moonrise, NULL, TRUE);
             g_string_append_printf(text, _("<tt><small>"
                                            "Moonrise: %s"
                                            "</small></tt>\n"), moonrise);
             g_free(moonrise);
 
-            moonset = format_date(astro->moonset, NULL, FALSE);
+            moonset = format_date(astro->moonset, NULL, TRUE);
             g_string_append_printf(text, _("<tt><small>"
                                            "Moonset:  %s"
                                            "</small></tt>"), moonset);
