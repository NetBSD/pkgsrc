$NetBSD: patch-chrome_browser_ui_webui_chrome__web__ui__controller__factory.cc,v 1.25 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -117,17 +117,17 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -268,7 +268,7 @@ void ChromeWebUIControllerFactory::GetFa
     const std::vector<int>& desired_sizes_in_pixel,
     favicon_base::FaviconResultsCallback callback) const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.SchemeIs(webapps::kIsolatedAppScheme)) {
     ReadIsolatedWebAppFaviconsFromDisk(profile, page_url, std::move(callback));
     return;
@@ -427,7 +427,7 @@ base::RefCountedMemory* ChromeWebUIContr
     return NewTabPageUI::GetFaviconResourceBytes(scale_factor);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIWhatsNewHost) {
     return WhatsNewUI::GetFaviconResourceBytes(scale_factor);
   }
@@ -457,7 +457,7 @@ base::RefCountedMemory* ChromeWebUIContr
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIContextualTasksHost) {
     return ContextualTasksUI::GetFaviconResourceBytes(scale_factor);
   }
