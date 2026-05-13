$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_libANGLE_Display.cpp,v 1.3 2026/05/13 05:31:25 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp.orig	2026-05-08 07:54:08.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp
@@ -60,7 +60,7 @@
 #        include "libANGLE/renderer/gl/wgl/DisplayWGL.h"
 #    elif ANGLE_ENABLE_CGL
 #        include "libANGLE/renderer/gl/cgl/DisplayCGL.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        include "libANGLE/renderer/gl/egl/DisplayEGL.h"
 #        if defined(ANGLE_USE_X11) && defined(ANGLE_USE_X11_GLX)
 #            include "libANGLE/renderer/gl/glx/DisplayGLX_api.h"
@@ -424,7 +424,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             impl = new rx::DisplayCGL(state);
             break;
 
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM) || defined(ANGLE_USE_WAYLAND)
             if (platformType == 0)
             {
@@ -482,7 +482,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM) || defined(ANGLE_USE_WAYLAND)
             if (platformType == 0)
             {
@@ -545,7 +545,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
                 impl = rx::CreateVulkanWin32Display(state);
             }
             break;
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == EGL_PLATFORM_GBM_KHR && rx::IsVulkanGbmDisplayAvailable())
             {
@@ -2194,7 +2194,7 @@ static ClientExtensions GenerateClientEx
     extensions.platformWaylandEXT = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX) && (defined(ANGLE_ENABLE_OPENGL) || defined(ANGLE_ENABLE_VULKAN))
+#if (defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)) && (defined(ANGLE_ENABLE_OPENGL) || defined(ANGLE_ENABLE_VULKAN))
     extensions.platformSurfacelessMESA = true;
 #endif
 
@@ -2241,7 +2241,7 @@ static ClientExtensions GenerateClientEx
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
