--- src/unix/fcitx/fcitx_mozc.cc.orig	2019-03-04 18:35:55 UTC
+++ src/unix/fcitx/fcitx_mozc.cc
@@ -463,7 +463,7 @@ boolean ToolMenuAction(struct _FcitxUIMenu *menu, int 
             break;
     }
     
-    mozc::Process::SpawnProcess(mozc::FileUtil::JoinPath(mozc::SystemUtil::GetToolPath(), "mozc_tool"), args, &pid);
+    mozc::Process::SpawnProcess(mozc::FileUtil::JoinPath(mozc::SystemUtil::GetServerDirectory(), mozc::kMozcTool), args, &pid);
     return true;
 }
 
