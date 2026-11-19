$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.cc,v 1.13 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -343,7 +343,7 @@ void ChromeAutofillClient::AtMemoryCopyP
                                            ->GetPrimaryMainFrame()
                                            ->GetPageUkmSourceId())) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     client_->ShowAutofillAtMemoryPromo();
 #endif
   }
@@ -395,7 +395,7 @@ void ChromeAutofillClient::AtMemoryCopyP
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChromeAutofillClient::ShowAutofillAtMemoryPromo() {
   // TODO(crbug.com/519061643) Double check if we also need to check a field
   // url here.
