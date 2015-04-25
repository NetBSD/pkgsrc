$NetBSD: patch-hw_xfree86_os-support_bsd_sparc64__video.c,v 1.1 2015/04/25 11:47:03 tnn Exp $

For some reason we need these symbls to link.

--- hw/xfree86/os-support/bsd/sparc64_video.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ hw/xfree86/os-support/bsd/sparc64_video.c
@@ -43,3 +43,16 @@ xf86OSInitVidMem(VidMemInfoPtr pVidMem)
 {
     pVidMem->initialised = TRUE;
 }
+
+void
+xf86SetTVOut(int mode)
+{
+   return;
+}
+
+void
+xf86SetRGBOut()
+{
+    return;
+}
+
