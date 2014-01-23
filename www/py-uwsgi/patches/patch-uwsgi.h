$NetBSD: patch-uwsgi.h,v 1.5 2014/01/23 14:47:05 wiz Exp $

Avoid clash with sys/user.h inclusion in logging.c on DragonFly BSD.

--- uwsgi.h.orig	2013-12-30 08:44:59.000000000 +0000
+++ uwsgi.h
@@ -323,6 +323,10 @@ extern int pivot_root(const char *new_ro
 #elif defined(__CYGWIN__)
 #elif defined(__HURD__)
 #else
+#if defined(__DragonFly__)
+/* avoid clash with sys/user.h inclusion in logging.c */
+#define _KERNEL_STRUCTURES
+#endif /* __DragonFly__ */
 #include <sys/event.h>
 #endif
 
