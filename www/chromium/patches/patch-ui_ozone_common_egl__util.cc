$NetBSD: patch-ui_ozone_common_egl__util.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/common/egl_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/ozone/common/egl_util.cc
@@ -35,9 +35,9 @@ const base::FilePath::CharType kDefaultG
     FILE_PATH_LITERAL("libGLESv2.so");
 #else  // BUILDFLAG(IS_FUCHSIA)
 const base::FilePath::CharType kDefaultEglSoname[] =
-    FILE_PATH_LITERAL("libEGL.so.1");
+    FILE_PATH_LITERAL("libEGL.so");
 const base::FilePath::CharType kDefaultGlesSoname[] =
-    FILE_PATH_LITERAL("libGLESv2.so.2");
+    FILE_PATH_LITERAL("libGLESv2.so");
 #endif
 #if !BUILDFLAG(USE_STATIC_ANGLE)
 const base::FilePath::CharType kAngleEglSoname[] =
