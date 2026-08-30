$NetBSD: patch-Source_ThirdParty_ANGLE_src_libANGLE_renderer_gl_egl_DisplayEGL.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

Load unversioned library - libEGL.so.0 in X11R7, libEGL.so.1 in pkgsrc.

--- Source/ThirdParty/ANGLE/src/libANGLE/renderer/gl/egl/DisplayEGL.cpp.orig	2024-08-19 06:28:36.055373400 +0000
+++ Source/ThirdParty/ANGLE/src/libANGLE/renderer/gl/egl/DisplayEGL.cpp
@@ -112,6 +112,8 @@ const char *DisplayEGL::getEGLPath() con
 #    else
     return "/system/lib/libEGL.so";
 #    endif
+#elif defined(ANGLE_PLATFORM_NETBSD)
+    return "libEGL.so";
 #else
     return "libEGL.so.1";
 #endif
