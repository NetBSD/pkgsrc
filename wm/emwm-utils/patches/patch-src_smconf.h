$NetBSD: patch-src_smconf.h,v 1.1 2022/07/04 20:20:56 pin Exp $

Enable suspending from xmsm(1) on NetBSD.

--- src/smconf.h.orig	2022-04-12 15:12:11.000000000 +0000
+++ src/smconf.h
@@ -39,6 +39,8 @@
 #ifndef SUSPEND_CMD
 #ifdef __linux__
 #define SUSPEND_CMD     "/usr/sbin/pm-suspend"
+#elif __NetBSD__
+#define SUSPEND_CMD     "/sbin/sysctl -w hw.acpi.sleep.state=3"
 #else /* BSD */
 #define SUSPEND_CMD     "/usr/sbin/zzz"
 #endif /* _linux_ */
