$NetBSD: patch-chrome_browser_updater_updater.cc,v 1.4 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/updater/updater.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/updater/updater.cc
@@ -53,7 +53,7 @@ std::optional<mojom::AppState> GetLastKn
   return GetLastKnownUpdaterRegistrationStorage();
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void CheckForUpdate(
     base::RepeatingCallback<void(const UpdateService::UpdateState&)> callback) {
   base::ThreadPool::PostTaskAndReplyWithResult(
