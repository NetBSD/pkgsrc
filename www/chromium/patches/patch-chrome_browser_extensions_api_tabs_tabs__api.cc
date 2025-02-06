$NetBSD: patch-chrome_browser_extensions_api_tabs_tabs__api.cc,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -896,7 +896,7 @@ ExtensionFunction::ResponseAction Window
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (new_window->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->window()->Minimize();
