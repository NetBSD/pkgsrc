$NetBSD: patch-chrome_browser_ui_autofill_chrome__autofill__client.h,v 1.4 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -125,7 +125,7 @@ class ChromeAutofillClient : public Cont
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowAutofillAtMemoryPromo();
 #endif
 
@@ -346,7 +346,7 @@ class ChromeAutofillClient : public Cont
 
  protected:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   class AtMemoryPromoObserver : public content::WebContentsObserver {
    public:
     explicit AtMemoryPromoObserver(ChromeAutofillClient* client);
@@ -449,7 +449,7 @@ class ChromeAutofillClient : public Cont
   std::unique_ptr<ActorKeyMetricsRecorder> actor_key_metrics_recorder_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AtMemoryPromoObserver at_memory_promo_observer_{this};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
