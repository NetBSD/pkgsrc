$NetBSD: patch-chrome_browser_web__applications_os__integration_os__integration__manager.cc,v 1.24 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -673,7 +673,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrat
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   DCHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems);
