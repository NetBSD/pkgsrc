$NetBSD: patch-components_collaboration_public_collaboration__controller__delegate.h,v 1.16 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/collaboration/public/collaboration_controller_delegate.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/collaboration/public/collaboration_controller_delegate.h
@@ -124,7 +124,7 @@ class CollaborationControllerDelegate {
         case Type::kSigninDisabledByPolicy:
           error_header = l10n_util::GetStringUTF8(
               IDS_COLLABORATION_ENTREPRISE_SIGNIN_DISABLED_HEADER);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           error_body = l10n_util::GetStringUTF8(
               syncer::IsReplaceSyncPromosWithSignInPromosEnabled()
                   ? IDS_COLLABORATION_ENTREPRISE_SIGNIN_DISABLED_SYNC_HISTORY_BODY
