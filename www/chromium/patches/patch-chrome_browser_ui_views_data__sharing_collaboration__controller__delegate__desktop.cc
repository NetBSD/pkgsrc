$NetBSD: patch-chrome_browser_ui_views_data__sharing_collaboration__controller__delegate__desktop.cc,v 1.18 2026/09/22 13:41:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -97,7 +97,7 @@ DialogText GetPromptDialogTextFromStatus
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled() &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
     title_id = IDS_SYNC_HISTORY_TITLE;
@@ -434,7 +434,7 @@ void CollaborationControllerDelegateDesk
       chrome::ShowBrowserModal(browser_, std::move(dialog_model));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -519,7 +519,7 @@ void CollaborationControllerDelegateDesk
   }
 
   AccountInfo account_for_promo =
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       signin_ui_util::GetSingleAccountForPromos(
           IdentityManagerFactory::GetForProfile(browser_->GetProfile()),
           AccountPreviewDataServiceFactory::GetForProfile(
@@ -556,7 +556,7 @@ void CollaborationControllerDelegateDesk
               .SetLabel(dialog_text.ok_button_text)
               .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     dialog_builder.SetFootnote(ui::DialogModelLabel(dialog_text.footnote));
 
@@ -605,7 +605,7 @@ void CollaborationControllerDelegateDesk
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (syncer::IsReplaceSyncPromosWithSignInPromosEnabled()) {
     MaybeShowSignInUiForHistorySyncOptin();
     return;
