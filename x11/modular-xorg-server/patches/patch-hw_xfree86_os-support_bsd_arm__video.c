$NetBSD: patch-hw_xfree86_os-support_bsd_arm__video.c,v 1.1 2016/02/23 22:32:45 tnn Exp $

XXX stubs for now, sufficient for wsfb. Need to sync this file with xsrc.

--- hw/xfree86/os-support/bsd/arm_video.c.orig	2016-01-06 17:23:08.000000000 +0000
+++ hw/xfree86/os-support/bsd/arm_video.c
@@ -66,6 +66,12 @@
 #include "xf86_OSlib.h"
 #include "xf86OSpriv.h"
 
+#if defined(__NetBSD__)
+Bool xf86EnableIO(void) { return TRUE; }
+void xf86DisableIO(void) { return; }
+void xf86OSInitVidMem(VidMemInfoPtr pVidMem) { pVidMem->initialised = TRUE; }
+#else /* DISABLED */
+
 #if defined(__NetBSD__) && !defined(MAP_FILE)
 #define MAP_FLAGS MAP_SHARED
 #else
@@ -203,3 +209,4 @@ xf86DisableIO()
 }
 
 #endif                          /* USE_ARC_MMAP */
+#endif /* DISABLED */
