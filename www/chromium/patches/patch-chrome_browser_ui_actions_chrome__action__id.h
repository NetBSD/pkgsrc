$NetBSD: patch-chrome_browser_ui_actions_chrome__action__id.h,v 1.27 2026/09/29 07:42:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/actions/chrome_action_id.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -457,7 +457,7 @@
   E(kActionVisitDesktopOfLruUser3, IDC_VISIT_DESKTOP_OF_LRU_USER_3) \
   E(kActionVisitDesktopOfLruUser4, IDC_VISIT_DESKTOP_OF_LRU_USER_4) \
   E(kActionVisitDesktopOfLruUser5, IDC_VISIT_DESKTOP_OF_LRU_USER_5)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
