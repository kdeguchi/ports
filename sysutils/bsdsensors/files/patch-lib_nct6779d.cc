--- lib/nct6779d.cc.orig	2020-12-15 05:31:12 UTC
+++ lib/nct6779d.cc
@@ -29,7 +29,7 @@ std::map<NuvotonTempSource, uint8_t> kNCT6779DTempSour
 };
 
 NuvotonChipInfo kNCT6779D{
-    0xC561,
+    0xC562,
     "NCT6779D",
     {0, 0x4F},
     // Fan speed info
