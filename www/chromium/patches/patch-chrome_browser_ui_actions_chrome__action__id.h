$NetBSD: patch-chrome_browser_ui_actions_chrome__action__id.h,v 1.9 2025/11/04 14:55:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/actions/chrome_action_id.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -512,7 +512,7 @@
 #if BUILDFLAG(IS_CHROMEOS)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kToggleMultitaskMenu, IDC_TOGGLE_MULTITASK_MENU)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
