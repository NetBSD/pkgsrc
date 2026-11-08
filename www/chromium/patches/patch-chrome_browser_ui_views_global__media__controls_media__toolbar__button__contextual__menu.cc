$NetBSD: patch-chrome_browser_ui_views_global__media__controls_media__toolbar__button__contextual__menu.cc,v 1.1 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/global_media_controls/media_toolbar_button_contextual_menu.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/global_media_controls/media_toolbar_button_contextual_menu.cc
@@ -20,7 +20,7 @@
 #include "components/media_router/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/feedback_disabled_dialog.h"
 #endif
 
@@ -120,7 +120,7 @@ void MediaToolbarButtonContextualMenu::T
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 void MediaToolbarButtonContextualMenu::ReportIssue() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Cast uses its own feedback page (chrome://cast-feedback) instead of the
   // standard feedback dialog. However, when feedback submission is disabled,
   // chrome://cast-feedback is not available; display the FeedbackDisabledDialog
