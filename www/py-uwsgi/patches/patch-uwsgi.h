$NetBSD: patch-uwsgi.h,v 1.1 2011/04/08 12:26:29 adam Exp $

Clang does not handle inlines across source files.

--- uwsgi.h.orig	2011-04-08 10:10:46.000000000 +0000
+++ uwsgi.h
@@ -1710,8 +1710,13 @@ struct uwsgi_async_request {
 	struct uwsgi_async_request *next;
 };
 
+#if __clang__
+int event_queue_read(void);
+int event_queue_write(void);
+#else
 inline int event_queue_read(void);
 inline int event_queue_write(void);
+#endif
 
 void uwsgi_help(void);
 
