$NetBSD: patch-src_3rdparty_chromium_ui_gl_gl__fence.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gl/gl_fence.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/gl/gl_fence.cc
@@ -17,7 +17,7 @@
 #include "ui/gl/gl_surface_egl.h"
 #include "ui/gl/gl_version_info.h"
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #endif
