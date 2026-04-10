$NetBSD: patch-components_sync_service_sync__service__impl.cc,v 1.10 2026/04/10 17:31:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/service/sync_service_impl.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/sync/service/sync_service_impl.cc
@@ -1393,7 +1393,7 @@ void SyncServiceImpl::ReconfigureDataTyp
 
 void SyncServiceImpl::PassphraseTypeChanged(PassphraseType passphrase_type) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
-#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // If kReplaceSyncPromosWithSignInPromos is enabled, new users with custom
   // passphrase should have kAutofill disabled upon the initial sign-in. This is
   // done to prevent confusion, as addresses are NOT encrypted by the custom
