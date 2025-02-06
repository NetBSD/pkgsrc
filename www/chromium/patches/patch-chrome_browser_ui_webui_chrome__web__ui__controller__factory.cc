$NetBSD: patch-chrome_browser_ui_webui_chrome__web__ui__controller__factory.cc,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -130,16 +130,16 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/commerce/product_specifications_ui.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -465,7 +465,7 @@ base::RefCountedMemory* ChromeWebUIContr
   if (page_url.host_piece() == chrome::kChromeUINewTabPageHost)
     return NewTabPageUI::GetFaviconResourceBytes(scale_factor);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (page_url.host_piece() == chrome::kChromeUIWhatsNewHost)
     return WhatsNewUI::GetFaviconResourceBytes(scale_factor);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -493,7 +493,7 @@ base::RefCountedMemory* ChromeWebUIContr
     return ManagementUI::GetFaviconResourceBytes(scale_factor);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.host_piece() == commerce::kChromeUICompareHost) {
     return commerce::ProductSpecificationsUI::GetFaviconResourceBytes(
         scale_factor);
