--- glib/glibmm/ustring.cc.orig	2017-08-30 14:13:30 UTC
+++ glib/glibmm/ustring.cc
@@ -1364,7 +1364,7 @@ ustring::FormatStream::to_string() const
 #ifdef GLIBMM_HAVE_WIDE_STREAM
   const std::wstring str = stream_.str();
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1452,7 +1452,7 @@ operator>>(std::wistream& is, ustring& utf8_string)
   std::wstring wstr;
   is >> wstr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   glong n_bytes = 0;
   const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
@@ -1483,7 +1483,7 @@ operator<<(std::wostream& os, const ustring& utf8_stri
 {
   GError* error = nullptr;
 
-#if defined(__STDC_ISO_10646__) && SIZEOF_WCHAR_T == 4
+#if defined(__STDC_UTF_32__) && SIZEOF_WCHAR_T == 4
   // Avoid going through iconv if wchar_t always contains UCS-4.
   const auto buf = make_unique_ptr_gfree(
     g_utf8_to_ucs4(utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
