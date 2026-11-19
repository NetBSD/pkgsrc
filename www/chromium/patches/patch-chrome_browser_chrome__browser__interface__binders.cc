$NetBSD: patch-chrome_browser_chrome__browser__interface__binders.cc,v 1.33 2026/11/19 19:45:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_interface_binders.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -90,7 +90,7 @@
 #endif  // BUILDFLAG(ENABLE_UNHANDLED_TAP)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/screen_ai/screen_ai_service_router.h"
 #include "chrome/browser/screen_ai/screen_ai_service_router_factory.h"
 #include "chrome/browser/text_detection/text_detection_impl.h"
@@ -401,7 +401,7 @@ void BindMediaFoundationPreferences(
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void BindScreenAIAnnotator(
     content::RenderFrameHost* frame_host,
     mojo::PendingReceiver<screen_ai::mojom::ScreenAIAnnotator> receiver) {
@@ -588,7 +588,7 @@ void PopulateChromeFrameBinders(
 #endif  // BUILDFLAG(ENABLE_SPEECH_SERVICE)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(blink::features::kSubApps) &&
       !render_frame_host->GetParentOrOuterDocument()) {
     // The service binder will reject non-primary main frames, but we still need
