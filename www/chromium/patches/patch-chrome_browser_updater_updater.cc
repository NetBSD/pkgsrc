$NetBSD: patch-chrome_browser_updater_updater.cc,v 1.10 2026/09/02 13:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/updater/updater.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/updater/updater.cc
@@ -53,7 +53,7 @@ std::optional<mojom::AppState> GetLastKn
   return GetLastKnownUpdaterRegistrationStorage();
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void CheckForUpdate(
     base::RepeatingCallback<void(const UpdateService::UpdateState&)> callback) {
   base::ThreadPool::PostTaskAndReplyWithResult(
