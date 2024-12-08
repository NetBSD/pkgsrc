$NetBSD: patch-src_smconf.h,v 1.2 2024/12/08 15:09:54 vins Exp $

* Enable suspending from xmsm(1) on NetBSD.
* Support session management on SunOS. 

--- src/smconf.h.orig	2024-01-03 16:20:35.000000000 +0000
+++ src/smconf.h
@@ -27,18 +27,28 @@
 #ifndef SHUTDOWN_CMD
 #ifdef __linux__
 #define SHUTDOWN_CMD    "/sbin/poweroff"
+#elif __sun
+#define SHUTDOWN_CMD	"/usr/sbin/poweroff"
 #else
 #define SHUTDOWN_CMD    "/sbin/shutdown -p now"
 #endif
 #endif /* SHUTDOWN_CMD */
 
 #ifndef REBOOT_CMD
+#ifdef __sun
+#define REBOOT_CMD	"/usr/sbin/reboot"
+#else
 #define REBOOT_CMD      "/sbin/reboot"
 #endif
+#endif /* REBOOT_CMD */
 
 #ifndef SUSPEND_CMD
 #ifdef __linux__
 #define SUSPEND_CMD     "/usr/sbin/pm-suspend"
+#elif __NetBSD__
+#define SUSPEND_CMD     "/sbin/sysctl -w hw.acpi.sleep.state=3"
+#elif __sun
+#define SUSPEND_CMD	"/usr/bin/sys-suspend -x"
 #else /* BSD */
 #define SUSPEND_CMD     "/usr/sbin/zzz"
 #endif /* _linux_ */
