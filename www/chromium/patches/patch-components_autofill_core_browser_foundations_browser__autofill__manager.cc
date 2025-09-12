$NetBSD: patch-components_autofill_core_browser_foundations_browser__autofill__manager.cc,v 1.5 2025/09/12 16:02:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -779,7 +779,7 @@ BrowserAutofillManager::GetAmountExtract
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
