$NetBSD: patch-chrome_browser_devtools_features.cc,v 1.2 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/features.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/devtools/features.cc
@@ -164,7 +164,7 @@ BASE_FEATURE(kDevToolsNewPermissionDialo
              "DevToolsNewPermissionDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, DevTools does not accept remote debugging connections unless
 // using a non-default user data dir via the --user-data-dir switch.
 BASE_FEATURE(kDevToolsDebuggingRestrictions,
