$NetBSD: patch-Source_WebCore_platform_graphics_surfaces_mac_GraphicsSurfaceMac.cpp,v 1.1 2014/12/30 17:23:48 adam Exp $

Correct includes.

--- Source/WebCore/platform/graphics/surfaces/mac/GraphicsSurfaceMac.cpp.orig	2014-04-22 06:24:40.000000000 +0000
+++ Source/WebCore/platform/graphics/surfaces/mac/GraphicsSurfaceMac.cpp
@@ -23,9 +23,9 @@
 #if USE(GRAPHICS_SURFACE) && OS(DARWIN)
 #include "TextureMapperGL.h"
 #include <CoreFoundation/CFNumber.h>
-#include <CGLContext.h>
-#include <CGLCurrent.h>
-#include <CGLIOSurface.h>
+#include <OpenGL/CGLContext.h>
+#include <OpenGL/CGLCurrent.h>
+#include <OpenGL/CGLIOSurface.h>
 #include <IOSurface/IOSurface.h>
 #include <OpenGL/OpenGL.h>
 #include <OpenGL/gl.h>
