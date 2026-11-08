$NetBSD: patch-chrome_browser_ui_toolbar_cast_cast__toolbar__button__util.cc,v 1.1 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/toolbar/cast/cast_toolbar_button_util.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/toolbar/cast/cast_toolbar_button_util.cc
@@ -21,7 +21,7 @@
 #include "ui/base/base_window.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/feedback_disabled_dialog.h"
 #endif
 
@@ -103,7 +103,7 @@ void CastToolbarButtonUtil::AddCastChild
             base::BindRepeating(
                 [](BrowserWindowInterface* browser, actions::ActionItem* item,
                    actions::ActionInvocationContext context) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                   // Cast uses its own feedback page (chrome://cast-feedback)
                   // instead of the standard feedback dialog. However, when
                   // feedback submission is disabled, chrome://cast-feedback is
