$NetBSD: patch-chrome_browser_ui_views_tabs_hovercard_tab__hover__card__bubble__view.cc,v 1.6 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc
@@ -663,7 +663,7 @@ TabHoverCardBubbleView::TabHoverCardBubb
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
