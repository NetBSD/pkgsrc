$NetBSD: patch-chrome_browser_glic_public_features.cc,v 1.9 2026/09/29 07:42:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/public/features.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/glic/public/features.cc
@@ -86,7 +86,7 @@ BASE_FEATURE(kGlicCreateTabAdjacent, bas
 
 // When off, disables both live mode and the glic floating panel.
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
