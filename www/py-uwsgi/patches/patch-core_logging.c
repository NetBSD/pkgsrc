$NetBSD: patch-core_logging.c,v 1.3 2017/06/23 15:56:45 joerg Exp $

Fix build for Bitrig.

--- core/logging.c.orig	2017-03-30 22:11:36.000000000 +0000
+++ core/logging.c
@@ -1,8 +1,10 @@
 #ifndef __DragonFly__
 #include <uwsgi.h>
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__Bitrig__)
+#  if !defined(__NetBSD__)
 #include <sys/user.h>
+#  endif
 #include <sys/sysctl.h>
 #include <kvm.h>
 #elif defined(__sun__)
