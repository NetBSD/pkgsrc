$NetBSD: patch-core_logging.c,v 1.2 2016/11/04 21:39:00 maya Exp $

Fix build for Bitrig.

--- core/logging.c.orig	2016-10-03 08:16:59.000000000 +0000
+++ core/logging.c
@@ -1,7 +1,7 @@
 #ifndef __DragonFly__
 #include <uwsgi.h>
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__Bitrig__)
 #include <sys/user.h>
 #include <sys/sysctl.h>
 #include <kvm.h>
