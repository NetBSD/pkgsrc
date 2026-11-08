$NetBSD: patch-chrome_browser_extensions_api_tabs_windows__api.cc,v 1.1 2026/11/08 15:38:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/tabs/windows_api.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/extensions/api/tabs/windows_api.cc
@@ -932,7 +932,7 @@ ExtensionFunction::ResponseValue Windows
 // created as minimized.
 // TODO(crbug.com/40254339): Remove this workaround when linux is fixed.
 // TODO(crbug.com/40254339): Find a fix for wayland as well.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))  && BUILDFLAG(SUPPORTS_OZONE_X11)
   if (BrowserInitState::From(new_window)->initial_show_state() ==
       ui::mojom::WindowShowState::kMinimized) {
     new_window->GetWindow()->Minimize();
