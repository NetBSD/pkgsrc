$NetBSD: patch-core_logging.c,v 1.5 2022/11/02 07:26:47 wiz Exp $

Fix build for NetBSD.
https://github.com/unbit/uwsgi/pull/2506

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
