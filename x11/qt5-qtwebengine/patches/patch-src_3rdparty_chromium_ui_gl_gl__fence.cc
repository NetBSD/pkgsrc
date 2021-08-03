$NetBSD: patch-src_3rdparty_chromium_ui_gl_gl__fence.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gl/gl_fence.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gl/gl_fence.cc
@@ -18,7 +18,7 @@
 #include "ui/gl/gl_fence_apple.h"
 #endif
 
-#if defined(USE_EGL) && defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(USE_EGL) && defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #include "ui/gl/gl_surface_egl.h"
