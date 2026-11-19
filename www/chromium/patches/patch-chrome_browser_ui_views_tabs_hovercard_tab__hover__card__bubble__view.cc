$NetBSD: patch-chrome_browser_ui_views_tabs_hovercard_tab__hover__card__bubble__view.cc,v 1.15 2026/11/19 19:45:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/tabs/hovercard/tab_hover_card_bubble_view.cc
@@ -662,7 +662,7 @@ TabHoverCardBubbleView::TabHoverCardBubb
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
   set_accept_drag_drop(false);
