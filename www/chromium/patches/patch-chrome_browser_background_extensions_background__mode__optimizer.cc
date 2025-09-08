$NetBSD: patch-chrome_browser_background_extensions_background__mode__optimizer.cc,v 1.5 2025/09/08 13:24:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/extensions/background_mode_optimizer.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/background/extensions/background_mode_optimizer.cc
@@ -31,7 +31,7 @@ std::unique_ptr<BackgroundModeOptimizer>
     return nullptr;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart)) {
     // Private ctor.
     return base::WrapUnique(new BackgroundModeOptimizer());
