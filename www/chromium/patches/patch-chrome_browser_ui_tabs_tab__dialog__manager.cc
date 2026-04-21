$NetBSD: patch-chrome_browser_ui_tabs_tab__dialog__manager.cc,v 1.17 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -90,7 +90,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
