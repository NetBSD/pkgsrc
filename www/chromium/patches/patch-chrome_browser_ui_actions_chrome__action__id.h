$NetBSD: patch-chrome_browser_ui_actions_chrome__action__id.h,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/actions/chrome_action_id.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -513,7 +513,7 @@
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_ANSWER) \
   E(kActionContentContextQuickAnswersInlineQuery, \
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_QUERY)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
