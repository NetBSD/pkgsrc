$NetBSD: patch-hw_xfree86_os-support_xf86_OSproc.h,v 1.1 2016/02/23 22:32:45 tnn Exp $

These are in i386_video.c only. XXX what are they used for?

--- hw/xfree86/os-support/xf86_OSproc.h.orig	2016-01-06 17:23:08.000000000 +0000
+++ hw/xfree86/os-support/xf86_OSproc.h
@@ -115,7 +115,7 @@ _XFUNCPROTOBEGIN
 extern _X_EXPORT Bool xf86EnableIO(void);
 extern _X_EXPORT void xf86DisableIO(void);
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && (defined(__i386__) || defined(__x86_64__))
 extern _X_EXPORT void xf86SetTVOut(int);
 extern _X_EXPORT void xf86SetRGBOut(void);
 #endif
