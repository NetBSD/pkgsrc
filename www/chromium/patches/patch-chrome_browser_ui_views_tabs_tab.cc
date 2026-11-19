$NetBSD: patch-chrome_browser_ui_views_tabs_tab.cc,v 1.33 2026/11/19 19:45:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -1516,7 +1516,7 @@ void Tab::MaybeUpdateHoverStatus(const u
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
