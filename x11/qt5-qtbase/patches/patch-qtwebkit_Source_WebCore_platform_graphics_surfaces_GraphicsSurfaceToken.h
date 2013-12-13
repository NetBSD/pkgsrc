$NetBSD: patch-qtwebkit_Source_WebCore_platform_graphics_surfaces_GraphicsSurfaceToken.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Treat *BSD like Linux

--- qtwebkit/Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h.orig	2013-11-27 01:01:44.000000000 +0000
+++ qtwebkit/Source/WebCore/platform/graphics/surfaces/GraphicsSurfaceToken.h
@@ -35,7 +35,7 @@ struct GraphicsSurfaceToken {
 
 #if OS(DARWIN)
     typedef mach_port_t BufferHandle;
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
     typedef uint32_t BufferHandle;
 #elif OS(WINDOWS)
     typedef HANDLE BufferHandle;
