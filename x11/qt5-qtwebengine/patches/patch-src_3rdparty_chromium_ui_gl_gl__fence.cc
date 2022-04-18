$NetBSD: patch-src_3rdparty_chromium_ui_gl_gl__fence.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gl/gl_fence.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gl/gl_fence.cc
@@ -18,7 +18,7 @@
 #include "ui/gl/gl_fence_apple.h"
 #endif
 
-#if defined(USE_EGL) && defined(OS_POSIX) && !defined(OS_APPLE)
+#if defined(USE_EGL) && defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #include "ui/gl/gl_surface_egl.h"
