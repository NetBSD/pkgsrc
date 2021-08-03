$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_about__ui.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/ui/webui/about_ui.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/about_ui.cc
@@ -564,7 +564,7 @@ std::string ChromeURLs() {
   return html;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -620,7 +620,7 @@ void AboutUIHTMLSource::StartDataRequest
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
