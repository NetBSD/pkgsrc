$NetBSD: patch-chrome_browser_ui_tabs_tab__features.cc,v 1.5 2025/09/12 16:02:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_features.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -356,7 +356,7 @@ void TabFeatures::Init(TabInterface& tab
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 #endif
