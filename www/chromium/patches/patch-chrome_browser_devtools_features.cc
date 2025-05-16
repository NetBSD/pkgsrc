$NetBSD: patch-chrome_browser_devtools_features.cc,v 1.1 2025/05/16 16:08:16 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/features.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/devtools/features.cc
@@ -157,7 +157,7 @@ BASE_FEATURE(kDevToolsAiGeneratedTimelin
              "DevToolsAiGeneratedTimelineLabels",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, DevTools does not accept remote debugging connections unless
 // using a non-default user data dir via the --user-data-dir switch.
 BASE_FEATURE(kDevToolsDebuggingRestrictions,
