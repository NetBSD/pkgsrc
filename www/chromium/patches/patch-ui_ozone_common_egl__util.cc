$NetBSD: patch-ui_ozone_common_egl__util.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/common/egl_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/common/egl_util.cc
@@ -26,9 +26,9 @@ const base::FilePath::CharType kDefaultG
     FILE_PATH_LITERAL("libGLESv2.so");
 #else  // BUILDFLAG(IS_FUCHSIA)
 const base::FilePath::CharType kDefaultEglSoname[] =
-    FILE_PATH_LITERAL("libEGL.so.1");
+    FILE_PATH_LITERAL("libEGL.so");
 const base::FilePath::CharType kDefaultGlesSoname[] =
-    FILE_PATH_LITERAL("libGLESv2.so.2");
+    FILE_PATH_LITERAL("libGLESv2.so");
 #endif
 const base::FilePath::CharType kAngleEglSoname[] =
     FILE_PATH_LITERAL("libEGL.so");
