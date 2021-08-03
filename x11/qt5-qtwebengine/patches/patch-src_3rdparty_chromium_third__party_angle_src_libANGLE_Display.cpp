$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_libANGLE_Display.cpp,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp
@@ -54,7 +54,7 @@
 #        include "libANGLE/renderer/gl/cgl/DisplayCGL.h"
 #    elif defined(ANGLE_PLATFORM_IOS)
 #        include "libANGLE/renderer/gl/eagl/DisplayEAGL.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
 #            include "libANGLE/renderer/gl/egl/ozone/DisplayOzone.h"
 #        else
@@ -252,7 +252,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             impl = new rx::DisplayCGL(state);
 #    elif defined(ANGLE_PLATFORM_IOS)
             impl = new rx::DisplayEAGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
             // This might work but has never been tried, so disallow for now.
             impl = nullptr;
@@ -284,7 +284,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_OZONE)
             impl = new rx::DisplayOzone(state);
 #        else
@@ -315,7 +315,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             {
                 impl = rx::CreateVulkanWin32Display(state);
             }
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
             if (rx::IsVulkanXcbDisplayAvailable())
             {
                 impl = rx::CreateVulkanXcbDisplay(state);
@@ -1387,7 +1387,7 @@ static ClientExtensions GenerateClientEx
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX) && !defined(ANGLE_USE_OZONE)
+#if defined(ANGLE_PLATFORM_POSIX) && !defined(ANGLE_USE_OZONE)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
