$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.cc,v 1.5 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -327,14 +327,14 @@ void ChromeAutofillClient::AtMemoryCopyP
                                            ->GetPrimaryMainFrame()
                                            ->GetPageUkmSourceId())) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     client_->ShowAutofillAtMemoryPromo();
 #endif
   }
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChromeAutofillClient::ShowAutofillAtMemoryPromo() {
   // TODO(crbug.com/519061643) Double check if we also need to check a field
   // url here.
