$NetBSD: patch-chrome_browser_picture__in__picture_picture__in__picture__window__manager.cc,v 1.9 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/picture_in_picture/picture_in_picture_window_manager.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/picture_in_picture/picture_in_picture_window_manager.cc
@@ -21,7 +21,7 @@
 #include "ui/gfx/geometry/resize_utils.h"
 #include "ui/gfx/geometry/size.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -586,7 +586,7 @@ void PictureInPictureWindowManager::SetW
 bool PictureInPictureWindowManager::IsSupportedForDocumentPictureInPicture(
     const GURL& url) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Only allow document PiP to be opened if the URL is of a type that we know
   // how to display in the title bar.  Otherwise, the title bar might be
   // misleading in certain scenarios.  See https://crbug.com/1460025 .
