$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_browser_personal__data__manager.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/autofill/core/browser/personal_data_manager.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/browser/personal_data_manager.cc
@@ -1916,7 +1916,7 @@ bool PersonalDataManager::IsServerCard(c
 
 bool PersonalDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows and Mac.
-#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) || \
+#if (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) || \
     defined(OS_CHROMEOS)
   return false;
 #else
@@ -1940,7 +1940,7 @@ bool PersonalDataManager::ShouldShowCard
 
   // The option should only be shown if the user has not already opted-in.
   return !is_opted_in;
-#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX)) ||
+#endif  // (!defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)) ||
         // defined(OS_CHROMEOS)
 }
 
