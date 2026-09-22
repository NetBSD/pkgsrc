$NetBSD: patch-base_threading_hang__watcher.cc,v 1.10 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/hang_watcher.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ base/threading/hang_watcher.cc
@@ -236,7 +236,7 @@ bool ThreadTypeLoggingLevelGreaterOrEqua
 
 constexpr base::FeatureState HangWatcherFeatureDefault() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FEATURE_ENABLED_BY_DEFAULT;
 #else
   return FEATURE_DISABLED_BY_DEFAULT;
