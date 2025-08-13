$NetBSD: patch-chrome_browser_ui_actions_chrome__action__id.h,v 1.5 2025/08/13 07:44:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/actions/chrome_action_id.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -504,7 +504,7 @@
 #if BUILDFLAG(IS_CHROMEOS)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kToggleMultitaskMenu, IDC_TOGGLE_MULTITASK_MENU)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
