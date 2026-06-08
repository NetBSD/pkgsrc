$NetBSD: patch-chrome_browser_extensions_api_tabs_tabs__api.cc,v 1.13 2026/06/08 13:12:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -1365,7 +1365,7 @@ ExtensionFunction::ResponseValue Windows
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))&& BUILDFLAG(SUPPORTS_OZONE_X11)
   if (new_window->GetBrowserForMigrationOnly()->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
