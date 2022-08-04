--- src/gui/base/win_util.cc.orig	2022-07-23 14:02:59 UTC
+++ src/gui/base/win_util.cc
@@ -144,6 +144,8 @@ bool AddTasksToList(CComPtr<ICustomDestinationList> de
 
   // TODO(yukawa): Investigate better way to localize strings.
   const LinkInfo kLinks[] = {
+      {"--mode=hand_writing", "Hand Wrinting", "手書き文字入力"},
+      {"--mode=character_palette", "Character Palette", "文字パレット"},
       {"--mode=dictionary_tool", "Dictionary Tool", "辞書ツール"},
       {"--mode=word_register_dialog", "Add Word", "単語登録"},
       {"--mode=config_dialog", "Properties", "プロパティ"},
