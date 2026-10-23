$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.h,v 1.11 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -133,7 +133,7 @@ class ChromeAutofillClient : public Cont
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Triggers the AtMemory promo bubble.
   void ShowAutofillAtMemoryPromo();
 #endif
