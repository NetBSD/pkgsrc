$NetBSD: patch-src_compat-api.h,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/compat-api.h.orig	2014-11-18 21:50:39.000000000 +0000
+++ src/compat-api.h
@@ -30,6 +30,7 @@
 
 #include <xorg-server.h>
 #include <xorgVersion.h>
+#include <xf86Module.h>
 
 #include <picturestr.h>
 #ifndef GLYPH_HAS_GLYPH_PICTURE_ACCESSOR
@@ -42,6 +43,10 @@
 #define xf86ScrnToScreen(s) screenInfo.screens[(s)->scrnIndex]
 #endif
 
+#if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) >= 22
+#define HAVE_NOTIFY_FD 1
+#endif
+
 #ifndef XF86_SCRN_INTERFACE
 
 #define SCRN_ARG_TYPE int
@@ -223,4 +228,14 @@ static inline void FreePixmap(PixmapPtr
 			  dstx, dsty)
 #endif
 
+#if ABI_VIDEODRV_VERSION >= SET_ABI_VERSION(22, 0)
+#define OsBlockSIGIO()
+#define OsReleaseSIGIO()
+#endif
+
+#if !HAVE_NOTIFY_FD
+#define SetNotifyFd(fd, cb, mode, data) AddGeneralSocket(fd);
+#define RemoveNotifyFd(fd) RemoveGeneralSocket(fd)
+#endif
+
 #endif
