$NetBSD: patch-ksysguard_ksysguardd_NetBSD_ProcessList.c,v 1.2 2017/06/25 19:58:04 youri Exp $

--- ksysguard/ksysguardd/NetBSD/ProcessList.c.orig	2015-08-12 07:03:15.000000000 +0000
+++ ksysguard/ksysguardd/NetBSD/ProcessList.c
@@ -34,7 +34,7 @@
 #include <sys/sysctl.h>
 #include <sys/time.h>
 #include <sys/types.h>
-#include <sys/user.h>
+#include <sys/resource.h>
 #include <unistd.h>
 #include <signal.h>
 
