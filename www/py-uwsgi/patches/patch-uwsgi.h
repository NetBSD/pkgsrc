$NetBSD: patch-uwsgi.h,v 1.6 2015/04/06 02:35:54 rodent Exp $

Avoid clash with sys/user.h inclusion in logging.c on DragonFly BSD.

--- uwsgi.h.orig	2015-03-17 07:34:34.000000000 +0000
+++ uwsgi.h
@@ -327,6 +327,10 @@ extern int pivot_root(const char *new_ro
 #elif defined(__CYGWIN__)
 #elif defined(__HURD__)
 #else
+#if defined(__DragonFly__)
+/* avoid clash with sys/user.h inclusion in logging.c */
+#define _KERNEL_STRUCTURES
+#endif /* __DragonFly__ */
 #include <sys/event.h>
 #endif
 
