$NetBSD: patch-core_logging.c,v 1.4 2022/01/25 10:30:51 wiz Exp $

Fix build for NetBSD.

--- core/logging.c.orig	2021-10-06 05:22:45.000000000 +0000
+++ core/logging.c
@@ -2,7 +2,9 @@
 #include "uwsgi.h"
 #endif
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#  if !defined(__NetBSD__)
 #include <sys/user.h>
+#  endif
 #include <sys/sysctl.h>
 #include <kvm.h>
 #elif defined(__sun__)
