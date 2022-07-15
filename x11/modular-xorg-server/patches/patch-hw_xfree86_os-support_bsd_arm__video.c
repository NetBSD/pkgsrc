$NetBSD: patch-hw_xfree86_os-support_bsd_arm__video.c,v 1.2 2022/07/15 20:39:49 wiz Exp $

XXX stubs for now, sufficient for wsfb. Need to sync this file with xsrc.

--- hw/xfree86/os-support/bsd/arm_video.c.orig	2022-07-12 13:27:57.000000000 +0000
+++ hw/xfree86/os-support/bsd/arm_video.c
@@ -67,6 +67,12 @@
 #include "xf86OSpriv.h"
 #include "compiler.h"
 
+#if defined(__NetBSD__)
+Bool xf86EnableIO(void) { return TRUE; }
+void xf86DisableIO(void) { return; }
+void xf86OSInitVidMem(VidMemInfoPtr pVidMem) { pVidMem->initialised = TRUE; }
+#else /* DISABLED */
+
 #if defined(__NetBSD__) && !defined(MAP_FILE)
 #define MAP_FLAGS MAP_SHARED
 #else
@@ -206,3 +212,4 @@ xf86DisableIO()
 }
 
 #endif                          /* USE_ARC_MMAP */
+#endif /* DISABLED */
