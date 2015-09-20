$NetBSD: patch-hw_xfree86_os-support_bsd_sparc64__video.c,v 1.1 2015/09/20 16:39:18 tnn Exp $

For some reason we need these symbols to link.

--- hw/xfree86/os-support/bsd/sparc64_video.c.orig	2012-05-17 17:09:03.000000000 +0000
+++ hw/xfree86/os-support/bsd/sparc64_video.c
@@ -50,6 +50,19 @@ xf86OSInitVidMem(VidMemInfoPtr pVidMem)
     pVidMem->initialised = TRUE;
 }
 
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
+
 static pointer
 sparc64MapVidMem(int ScreenNum, unsigned long Base, unsigned long Size,
                  int flags)
