$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.h,v 1.1 2026/06/08 13:12:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -121,7 +121,7 @@ class ChromeAutofillClient : public Cont
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowAutofillAtMemoryPromo();
 #endif
 
@@ -394,7 +394,7 @@ class ChromeAutofillClient : public Cont
   std::unique_ptr<ActorKeyMetricsRecorder> actor_key_metrics_recorder_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   class AtMemoryPromoObserver : public content::WebContentsObserver {
    public:
     explicit AtMemoryPromoObserver(ChromeAutofillClient* client);
