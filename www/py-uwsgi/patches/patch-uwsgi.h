$NetBSD: patch-uwsgi.h,v 1.4 2014/01/04 13:56:01 rodent Exp $

--- uwsgi.h.orig	2013-08-23 12:51:18.000000000 +0000
+++ uwsgi.h
@@ -278,6 +278,10 @@ extern int pivot_root(const char *new_ro
 #include <sys/devpoll.h>
 #elif defined(__HAIKU__)
 #else
+#ifdef __DragonFly__
+/* avoid clash with sys/user.h inclusion in logging.c */
+#define _KERNEL_STRUCTURES 
+#endif /* __DragonFly__ */
 #include <sys/event.h>
 #endif
 
