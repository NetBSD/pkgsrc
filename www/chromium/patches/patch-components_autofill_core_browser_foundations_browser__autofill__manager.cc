$NetBSD: patch-components_autofill_core_browser_foundations_browser__autofill__manager.cc,v 1.11 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -854,7 +854,7 @@ BrowserAutofillManager::GetAmountExtract
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
