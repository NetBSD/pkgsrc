$NetBSD: patch-hw_xfree86_os-support_bsd_bsd__init.c,v 1.1 2018/10/26 10:20:12 maya Exp $

Don't error when running unprivileged.

--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2018-10-25 14:13:21.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -165,10 +165,12 @@ xf86OpenConsole()
 #endif
 
     if (serverGeneration == 1) {
+#if 0
         /* check if we are run with euid==0 */
         if (geteuid() != 0) {
             FatalError("xf86OpenConsole: Server must be suid root");
         }
+#endif
 
         if (!KeepTty) {
             /*
