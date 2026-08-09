$NetBSD: patch-chrome_browser_updater_updater.cc,v 1.9 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/updater/updater.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/updater/updater.cc
@@ -53,7 +53,7 @@ std::optional<mojom::AppState> GetLastKn
   return GetLastKnownUpdaterRegistrationStorage();
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void CheckForUpdate(
     base::RepeatingCallback<void(const UpdateService::UpdateState&)> callback) {
   base::ThreadPool::PostTaskAndReplyWithResult(
