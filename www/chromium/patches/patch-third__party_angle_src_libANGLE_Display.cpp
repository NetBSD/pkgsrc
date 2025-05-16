$NetBSD: patch-third__party_angle_src_libANGLE_Display.cpp,v 1.2 2025/05/16 16:08:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/libANGLE/Display.cpp.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -58,7 +58,7 @@
 #        include "libANGLE/renderer/gl/wgl/DisplayWGL.h"
 #    elif ANGLE_ENABLE_CGL
 #        include "libANGLE/renderer/gl/cgl/DisplayCGL.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        include "libANGLE/renderer/gl/egl/DisplayEGL.h"
 #        if defined(ANGLE_USE_X11)
 #            include "libANGLE/renderer/gl/glx/DisplayGLX_api.h"
@@ -422,7 +422,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             impl = new rx::DisplayCGL(state);
             break;
 
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -468,7 +468,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -519,7 +519,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
                 impl = rx::CreateVulkanWin32Display(state);
             }
             break;
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == EGL_PLATFORM_GBM_KHR && rx::IsVulkanGbmDisplayAvailable())
             {
@@ -2133,7 +2133,7 @@ static ClientExtensions GenerateClientEx
     extensions.platformWaylandEXT = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX) && (defined(ANGLE_ENABLE_OPENGL) || defined(ANGLE_ENABLE_VULKAN))
+#if (defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)) && (defined(ANGLE_ENABLE_OPENGL) || defined(ANGLE_ENABLE_VULKAN))
     extensions.platformSurfacelessMESA = true;
 #endif
 
@@ -2180,7 +2180,7 @@ static ClientExtensions GenerateClientEx
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
