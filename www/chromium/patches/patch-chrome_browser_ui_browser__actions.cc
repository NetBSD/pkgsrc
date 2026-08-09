$NetBSD: patch-chrome_browser_ui_browser__actions.cc,v 1.1 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_actions.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/browser_actions.cc
@@ -223,7 +223,7 @@
 #include "chrome/browser/ui/views/download/bubble/download_toolbar_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -2197,7 +2197,7 @@ void BrowserActions::InitializeToolbarAn
           .Build());
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -2292,7 +2292,7 @@ void BrowserActions::InitializeToolbarAn
           .SetActionId(kActionExit)
           .Build());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -3226,7 +3226,7 @@ void BrowserActions::InitializeToolbarAn
           base::BindRepeating(
               [](BrowserWindowInterface* bwi, actions::ActionItem* item,
                  actions::ActionInvocationContext context) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                 chrome::CreateDesktopShortcutForActiveWebContents(
                     bwi->GetBrowserForMigrationOnly());
 #else
@@ -3867,7 +3867,7 @@ void BrowserActions::InitializeToolbarAn
 #endif
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
