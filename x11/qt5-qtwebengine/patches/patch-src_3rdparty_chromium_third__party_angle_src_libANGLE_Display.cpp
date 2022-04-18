$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_libANGLE_Display.cpp,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/Display.cpp
@@ -55,7 +55,7 @@
 #        include "libANGLE/renderer/gl/cgl/DisplayCGL.h"
 #    elif defined(ANGLE_PLATFORM_IOS)
 #        include "libANGLE/renderer/gl/eagl/DisplayEAGL.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        include "libANGLE/renderer/gl/egl/DisplayEGL.h"
 #        if defined(ANGLE_USE_GBM)
 #            include "libANGLE/renderer/gl/egl/gbm/DisplayGbm.h"
@@ -264,7 +264,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             impl = new rx::DisplayCGL(state);
 #    elif defined(ANGLE_PLATFORM_IOS)
             impl = new rx::DisplayEAGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -305,7 +305,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -346,7 +346,7 @@ rx::DisplayImpl *CreateDisplayFromAttrib
             {
                 impl = rx::CreateVulkanWin32Display(state);
             }
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_POSIX)
 #        if defined(ANGLE_USE_X11)
             if (platformType == EGL_PLATFORM_X11_EXT && rx::IsVulkanXcbDisplayAvailable())
             {
@@ -1612,7 +1612,7 @@ static ClientExtensions GenerateClientEx
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
