$NetBSD: patch-libxfsm_xfsm-shutdown-common.h,v 1.2 2022/02/06 17:42:47 gutteridge Exp $

Add NetBSD commands.

--- libxfsm/xfsm-shutdown-common.h.orig	2019-05-05 22:00:21.000000000 +0000
+++ libxfsm/xfsm-shutdown-common.h
@@ -70,4 +70,9 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
 
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND      "/sbin/sysctl -w hw.acpi.sleep.state=3"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/sbin/sysctl -w hw.acpi.sleep.state=4"
+#endif
+
 #endif /* __XFSM_SHUTDOWN_COMMON_H_ */
