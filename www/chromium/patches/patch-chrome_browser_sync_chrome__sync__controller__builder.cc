$NetBSD: patch-chrome_browser_sync_chrome__sync__controller__builder.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/chrome_sync_controller_builder.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/sync/chrome_sync_controller_builder.cc
@@ -297,7 +297,7 @@ ChromeSyncControllerBuilder::Build(synce
 #if BUILDFLAG(ENABLE_SPELLCHECK)
     // Chrome prefers OS provided spell checkers where they exist. So only sync
     // the custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Dictionary sync is enabled by default.
     if (spellcheck_service_.value()) {
       controllers.push_back(
