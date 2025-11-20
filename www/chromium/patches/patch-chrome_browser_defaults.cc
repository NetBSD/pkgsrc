$NetBSD: patch-chrome_browser_defaults.cc,v 1.10 2025/11/20 08:36:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/defaults.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/defaults.cc
@@ -31,7 +31,7 @@ const bool kAlwaysCreateTabbedBrowserOnS
 const bool kShowHelpMenuItemIcon = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
