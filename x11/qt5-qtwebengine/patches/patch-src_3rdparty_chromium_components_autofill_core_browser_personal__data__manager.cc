$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_browser_personal__data__manager.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/autofill/core/browser/personal_data_manager.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/browser/personal_data_manager.cc
@@ -1961,7 +1961,7 @@ bool PersonalDataManager::IsServerCard(c
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
 #if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN) || \
-    defined(OS_APPLE)
+    defined(OS_APPLE) || defined(OS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   if (!sync_service_ || sync_service_->IsSyncFeatureEnabled() ||
