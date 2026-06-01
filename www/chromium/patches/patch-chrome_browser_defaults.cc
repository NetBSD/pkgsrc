$NetBSD: patch-chrome_browser_defaults.cc,v 1.20 2026/06/01 10:09:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/defaults.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/defaults.cc
@@ -30,7 +30,7 @@ const bool kAlwaysCreateTabbedBrowserOnS
 const bool kShowHelpMenuItemIcon = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
