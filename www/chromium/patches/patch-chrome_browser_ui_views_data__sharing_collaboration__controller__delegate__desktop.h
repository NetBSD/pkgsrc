$NetBSD: patch-chrome_browser_ui_views_data__sharing_collaboration__controller__delegate__desktop.h,v 1.7 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.h
@@ -84,7 +84,7 @@ class CollaborationControllerDelegateDes
       std::optional<data_sharing::mojom::GroupActionProgress> progress);
 
   void ShowErrorDialog(const ErrorInfo& error);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSignInUiForHistorySyncOptin();
 #endif
   void MaybeShowSignInAndSyncUi();
