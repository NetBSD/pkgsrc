$NetBSD: patch-xfsm-shutdown-helper_main.c,v 1.1 2015/07/02 13:15:58 youri Exp $

Add NetBSD commands.
--- xfsm-shutdown-helper/main.c.orig	2014-08-28 15:52:27.000000000 +0000
+++ xfsm-shutdown-helper/main.c
@@ -91,7 +91,10 @@
 #define UP_BACKEND_SUSPEND_COMMAND	"/usr/sbin/zzz"
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
-
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND      "/usr/sbin/zzz"
+#define UP_BACKEND_HIBERNATE_COMMAND    "/usr/sbin/zzz"
+#endif
 
 static gboolean
 run (const gchar *command)
