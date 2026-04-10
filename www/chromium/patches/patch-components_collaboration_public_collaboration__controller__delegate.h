$NetBSD: patch-components_collaboration_public_collaboration__controller__delegate.h,v 1.9 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/collaboration/public/collaboration_controller_delegate.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/collaboration/public/collaboration_controller_delegate.h
@@ -125,7 +125,7 @@ class CollaborationControllerDelegate {
         case Type::kSigninDisabledByPolicy:
           error_header = l10n_util::GetStringUTF8(
               IDS_COLLABORATION_ENTREPRISE_SIGNIN_DISABLED_HEADER);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           error_body = l10n_util::GetStringUTF8(
               base::FeatureList::IsEnabled(
                   syncer::kReplaceSyncPromosWithSignInPromos)
