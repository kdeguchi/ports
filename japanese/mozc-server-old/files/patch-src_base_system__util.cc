--- src/base/system_util.cc.orig	2023-07-19 07:02:33 UTC
+++ src/base/system_util.cc
@@ -499,11 +499,15 @@ std::string SystemUtil::GetUserNameAsString() {
   DCHECK_NE(FALSE, result);
   return win32::WideToUtf8(wusername);
 #else   // _WIN32
+  /*
   const int bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
   CHECK_NE(bufsize, -1);
   absl::FixedArray<char> buf(bufsize);
+  */
   struct passwd pw, *ppw;
-  CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf.data(), buf.size(), &ppw));
+  //CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf.data(), buf.size(), &ppw));
+  char buf[1024];
+  CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf, sizeof(buf), &ppw));
   return pw.pw_name;
 #endif  // !_WIN32
 }
