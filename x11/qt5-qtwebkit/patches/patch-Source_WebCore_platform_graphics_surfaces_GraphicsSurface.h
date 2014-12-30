$NetBSD: patch-Source_WebCore_platform_graphics_surfaces_GraphicsSurface.h,v 1.1 2014/12/30 17:23:48 adam Exp $

* Treat *BSD like Linux

--- Source/WebCore/platform/graphics/surfaces/GraphicsSurface.h.orig	2013-11-27 01:01:44.000000000 +0000
+++ Source/WebCore/platform/graphics/surfaces/GraphicsSurface.h
@@ -36,7 +36,7 @@ typedef struct __IOSurface* IOSurfaceRef
 typedef IOSurfaceRef PlatformGraphicsSurface;
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
 typedef uint32_t PlatformGraphicsSurface;
 #endif
 
