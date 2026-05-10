$NetBSD: patch-chrome_browser_ui_views_tabs_hovercard_tab__hover__card__bubble__view.cc,v 1.1 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc
@@ -673,7 +673,7 @@ TabHoverCardBubbleView::TabHoverCardBubb
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
