$NetBSD: patch-chrome_browser_ui_tabs_tab__strip__prefs.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_strip_prefs.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/tabs/tab_strip_prefs.cc
@@ -21,7 +21,7 @@ namespace tabs {
 
 bool GetDefaultTabSearchRightAligned() {
   // These platforms are all left aligned, the others should be right.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
