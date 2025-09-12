$NetBSD: patch-ui_gl_gl__fence.cc,v 1.7 2025/09/12 16:02:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gl/gl_fence.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/gl/gl_fence.cc
@@ -18,7 +18,7 @@
 #include "ui/gl/gl_surface_egl.h"
 #include "ui/gl/gl_version_info.h"
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #endif
