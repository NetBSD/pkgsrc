$NetBSD: patch-chrome_browser_ui_omnibox_omnibox__everywhere_omnibox__everywhere__event__handler__aura.cc,v 1.1 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/omnibox/omnibox_everywhere/omnibox_everywhere_event_handler_aura.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/omnibox/omnibox_everywhere/omnibox_everywhere_event_handler_aura.cc
@@ -20,7 +20,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "ui/views/widget/desktop_aura/desktop_drag_drop_client_win.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h"
 #endif
 
@@ -44,7 +44,7 @@ gfx::Point GetEventScreenPoint(const ui:
 base::ScopedClosureRunner SuppressDataDragsForWindowMove() {
 #if BUILDFLAG(IS_WIN)
   return views::DesktopDragDropClientWin::ScopedSuppressForWindowMove();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return views::DesktopDragDropClientOzone::ScopedSuppressForWindowMove();
 #else
   return base::ScopedClosureRunner();
