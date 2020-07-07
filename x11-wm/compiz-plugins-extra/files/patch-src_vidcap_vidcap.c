--- src/vidcap/vidcap.c.orig	2017-09-29 20:05:44 UTC
+++ src/vidcap/vidcap.c
@@ -620,7 +620,7 @@ thread_func(void *data)
 	char filename[256], ext[32];
 	int i, j, ret, found;
 
-	fd = open(RAWFILE, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC | O_LARGEFILE, 0644);
+	fd = open(RAWFILE, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
 
 	write_file(fd);
 
@@ -755,7 +755,7 @@ vidcapToggle(CompDisplay     *d,
 		header.width = d->screens->width;
 		header.height = d->screens->height;
 
-		vd->fd = open(WCAPFILE, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC | O_LARGEFILE, 0644);
+		vd->fd = open(WCAPFILE, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
 
 		ret = write(vd->fd, &header, sizeof (header));
 
