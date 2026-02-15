$NetBSD: patch-chrome_browser_ui_views_tabs_tab.cc,v 1.15 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -684,7 +684,7 @@ void Tab::MaybeUpdateHoverStatus(const u
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
