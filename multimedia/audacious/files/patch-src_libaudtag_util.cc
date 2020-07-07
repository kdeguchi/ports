--- src/libaudtag/util.cc.orig	2018-07-02 00:51:59 UTC
+++ src/libaudtag/util.cc
@@ -153,6 +153,29 @@ const char *convert_numericgenre_to_text(int numericge
         {GENRE_DRUM_SOLO, "Drum Solo"},
         {GENRE_A_CAPELLA, "A capella"},
         {GENRE_EURO_HOUSE, "Euro-House"},
+        {GENRE_DANCE_HALL, "Dance Hall"},
+        {GENRE_GOA, "Goa"},
+        {GENRE_DRUM_BASS, "Drum & Bass"},
+        {GENRE_CLUB_HOUSE, "Club-House"},
+        {GENRE_HARDCORE, "Hardcore"},
+        {GENRE_TERROR, "Terror"},
+        {GENRE_INDIE, "Indie"},
+        {GENRE_BRITPOP, "BritPop"},
+        {GENRE_NEGERPUNK, "Negerpunk"},
+        {GENRE_POLSK_PUNK, "Polsk Punk"},
+        {GENRE_BEAT, "Beat"},
+        {GENRE_CHRISTIAN_GANGSTA_RAP, "Christian Gangsta Rap"},
+        {GENRE_HEAVY_METAL, "Heavy Metal"},
+        {GENRE_BLACK_METAL, "Black Metal"},
+        {GENRE_CROSSOVER, "Crossover"},
+        {GENRE_CONTEMPORARY_CHRISTIAN, "Contemporary Christian"},
+        {GENRE_CHRISTIAN_ROCK, "Christian Rock"},
+        {GENRE_MERENGUE, "Merengue"},
+        {GENRE_SALSA, "Salsa"},
+        {GENRE_THRASH_METAL, "Thrash Metal"},
+        {GENRE_ANIME, "Anime"},
+        {GENRE_JPOP, "JPop"},
+        {GENRE_SYNTHPOP, "SynthPop"},
     };
 
     for (auto & pair : table)
