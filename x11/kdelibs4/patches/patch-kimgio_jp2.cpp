$NetBSD: patch-kimgio_jp2.cpp,v 1.1 2020/08/09 00:01:09 joerg Exp $

--- kimgio/jp2.cpp.orig	2020-08-08 22:34:50.646978346 +0000
+++ kimgio/jp2.cpp
@@ -103,13 +103,13 @@ static void jas_stream_initbuf(jas_strea
         stream->bufmode_ |= bufmode & JAS_STREAM_BUFMODEMASK;
 }
 
-static int qiodevice_read(jas_stream_obj_t *obj, char *buf, int cnt)
+static int qiodevice_read(jas_stream_obj_t *obj, char *buf, unsigned int cnt)
 {
         QIODevice *io = (QIODevice*) obj;
         return io->read(buf, cnt);
 }
 
-static int qiodevice_write(jas_stream_obj_t *obj, char *buf, int cnt)
+static int qiodevice_write(jas_stream_obj_t *obj, char *buf, unsigned int cnt)
 {
         QIODevice *io = (QIODevice*) obj;
         return io->write(buf, cnt);
