$NetBSD: patch-chrome_browser_ui_views_tabs_tab__hover__card__bubble__view.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc
@@ -381,7 +381,7 @@ TabHoverCardBubbleView::TabHoverCardBubb
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
