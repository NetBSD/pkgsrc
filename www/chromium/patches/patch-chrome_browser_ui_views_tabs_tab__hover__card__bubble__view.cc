$NetBSD: patch-chrome_browser_ui_views_tabs_tab__hover__card__bubble__view.cc,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc
@@ -376,7 +376,7 @@ TabHoverCardBubbleView::TabHoverCardBubb
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
