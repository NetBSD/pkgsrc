$NetBSD: patch-chrome_browser_ui_browser__actions.cc,v 1.9 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_actions.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/browser_actions.cc
@@ -257,7 +257,7 @@
 #include "chrome/browser/ui/views/download/bubble/download_toolbar_ui_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/util/managed_browser_utils.h"
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
@@ -2767,7 +2767,7 @@ void BrowserActions::InitializeToolbarAn
           .Build());
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -2926,7 +2926,7 @@ void BrowserActions::InitializeToolbarAn
           .SetAccelerator(GetAcceleratorForCommandId(IDC_EXIT))
           .Build());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
@@ -3895,7 +3895,7 @@ void BrowserActions::InitializeToolbarAn
               [](BrowserWindowInterface* bwi, actions::ActionItem* item,
                  actions::ActionInvocationContext context) {
                 base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                 chrome::CreateDesktopShortcutForActiveWebContents(bwi);
 #else
                 web_app::CreateWebAppFromCurrentWebContents(
@@ -4854,7 +4854,7 @@ void BrowserActions::InitializeToolbarAn
           IDS_CHROME_ENTERPRISE_RELEASE_NOTES,
           IDS_CHROME_ENTERPRISE_RELEASE_NOTES, omnibox::kChromeProductIcon,
           /*is_pinnable=*/false)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           .SetVisible(
               enterprise_util::IsBrowserManaged(profile) &&
               base::FeatureList::IsEnabled(features::kEnterpriseReleaseNotes))
@@ -4982,7 +4982,7 @@ void BrowserActions::InitializeToolbarAn
 #endif
 
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   root_action_item_->AddChild(
       actions::ActionItem::Builder(
           base::BindRepeating(
