$NetBSD: patch-chrome_browser_ui_tabs_tab__features.cc,v 1.12 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/ui/webui/webui_embedding_context.h"
 #include "components/contextual_tasks/public/features.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/wallet/chrome_walletable_pass_client.h"
 #endif
 #include "chrome/browser/ui/contextual_search/tab_contextualization_controller.h"
@@ -442,7 +442,7 @@ void TabFeatures::Init(TabInterface& tab
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
