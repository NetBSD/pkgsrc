$NetBSD: patch-chrome_browser_glic_public_features.cc,v 1.1 2026/05/10 15:29:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/public/features.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/glic/public/features.cc
@@ -44,7 +44,7 @@ BASE_FEATURE(kGlicInvoke, base::FEATURE_
 BASE_FEATURE(kGlicCreateTabAdjacent, base::FEATURE_ENABLED_BY_DEFAULT);
 
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
