$NetBSD: patch-chrome_browser_ui_tabs_tab__dialog__manager.cc,v 1.25 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -89,7 +89,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
