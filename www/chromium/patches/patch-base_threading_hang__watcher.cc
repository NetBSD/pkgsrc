$NetBSD: patch-base_threading_hang__watcher.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/hang_watcher.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/threading/hang_watcher.cc
@@ -352,7 +352,7 @@ void HangWatcher::InitializeOnMainThread
 
   bool enable_hang_watcher = base::FeatureList::IsEnabled(kEnableHangWatcher);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   if (is_zygote_child) {
     enable_hang_watcher =
         enable_hang_watcher &&
