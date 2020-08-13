--- glib/glibmm/ustring.cc.orig	2015-01-20 21:09:51.000000000 +0900
+++ glib/glibmm/ustring.cc	2015-11-24 23:56:24.643136000 +0900
@@ -1265,7 +1265,7 @@
 #ifdef GLIBMM_HAVE_WIDE_STREAM
   const std::wstring str = stream_.str();
 
-# if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+# if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const ScopedPtr<char> buf (g_ucs4_to_utf8(reinterpret_cast<const gunichar*>(str.data()),
@@ -1349,7 +1349,7 @@
   std::wstring wstr;
   is >> wstr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const ScopedPtr<char> buf (g_ucs4_to_utf8(reinterpret_cast<const gunichar*>(wstr.data()),
@@ -1380,7 +1380,7 @@
 {
   GError* error = 0;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   const ScopedPtr<gunichar> buf (g_utf8_to_ucs4(utf8_string.raw().data(),
                                                 utf8_string.raw().size(), 0, 0, &error));
