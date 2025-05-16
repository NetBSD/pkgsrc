$NetBSD: patch-chrome_updater_app_app__uninstall.cc,v 1.2 2025/05/16 16:08:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/app/app_uninstall.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/updater/app/app_uninstall.cc
@@ -157,7 +157,7 @@ void UninstallInThreadPool(UpdaterScope 
             }
             if (int result = UninstallOtherVersions(scope);
                 result != kErrorOk) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
               // TODO(crbug.com/366249606): Ignores the errors when uninstalls
               // the other versions, because currently older Linux updater on
               // CIPD exits with error `kErrorFailedToDeleteFolder`.
