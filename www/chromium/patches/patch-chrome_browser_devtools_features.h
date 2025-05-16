$NetBSD: patch-chrome_browser_devtools_features.h,v 1.1 2025/05/16 16:08:16 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/features.h.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/devtools/features.h
@@ -89,7 +89,7 @@ BASE_DECLARE_FEATURE(kDevToolsCssValueTr
 
 BASE_DECLARE_FEATURE(kDevToolsAiGeneratedTimelineLabels);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDevToolsDebuggingRestrictions);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
