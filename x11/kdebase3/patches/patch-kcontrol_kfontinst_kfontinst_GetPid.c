$NetBSD: patch-kcontrol_kfontinst_kfontinst_GetPid.c,v 1.2 2017/06/24 02:00:53 kamil Exp $

--- kcontrol/kfontinst/kfontinst/GetPid.c.orig	2007-05-14 07:55:38.000000000 +0000
+++ kcontrol/kfontinst/kfontinst/GetPid.c
@@ -28,6 +28,10 @@
 ////////////////////////////////////////////////////////////////////////////////
 */
 
+#ifdef __NetBSD__
+#define _KMEMUSER
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -172,7 +176,9 @@ unsigned int kfi_getPid(const char *proc
 #endif
 #include <sys/sysctl.h>
 #include <sys/time.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <unistd.h>
 unsigned int kfi_getPid(const char *proc, unsigned int ppid)
 {
