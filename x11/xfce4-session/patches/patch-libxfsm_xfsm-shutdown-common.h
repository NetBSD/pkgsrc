$NetBSD: patch-libxfsm_xfsm-shutdown-common.h,v 1.3 2023/06/06 01:14:53 gutteridge Exp $

Add NetBSD commands.

--- libxfsm/xfsm-shutdown-common.h.orig	2023-05-18 16:19:55.000000000 +0000
+++ libxfsm/xfsm-shutdown-common.h
@@ -70,6 +70,11 @@
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
 
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND      "/sbin/sysctl -w hw.acpi.sleep.state=3"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/sbin/sysctl -w hw.acpi.sleep.state=4"
+#endif
+
 #ifdef BACKEND_TYPE_SOLARIS
 #define UP_BACKEND_SUSPEND_COMMAND "/usr/bin/sys-suspend"
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/bin/false"
