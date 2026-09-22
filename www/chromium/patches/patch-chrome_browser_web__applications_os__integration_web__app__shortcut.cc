$NetBSD: patch-chrome_browser_web__applications_os__integration_web__app__shortcut.cc,v 1.26 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/web_app_shortcut.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.cc
@@ -228,7 +228,7 @@ std::unique_ptr<ShortcutInfo> BuildShort
 
 // TODO(crbug.com/40257107): Implement tests on Linux for using shortcuts_menu
 // actions.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       CreateShortcutsMenuItemInfos(state.shortcut_menus());
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
@@ -404,7 +404,7 @@ base::span<const int> GetDesiredIconSize
 #if BUILDFLAG(IS_MAC)
   static constexpr int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
   return kDesiredIconSizesForShortcut;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux supports icons of any size. FreeDesktop Icon Theme Specification
   // states that "Minimally you should install a 48x48 icon in the hicolor
   // theme."
