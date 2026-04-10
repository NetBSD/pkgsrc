$NetBSD: patch-chrome_browser_extensions_api_tabs_tabs__api.cc,v 1.9 2026/04/10 17:31:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1210,7 +1210,7 @@ ExtensionFunction::ResponseValue Windows
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))&& BUILDFLAG(SUPPORTS_OZONE_X11)
   if (new_window->GetBrowserForMigrationOnly()->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
