$NetBSD: patch-chrome_browser_ui_tabs_tab__dialog__manager.cc,v 1.1 2025/05/16 16:08:19 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -83,7 +83,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
