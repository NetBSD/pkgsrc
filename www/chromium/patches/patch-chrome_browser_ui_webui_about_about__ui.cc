$NetBSD: patch-chrome_browser_ui_webui_about_about__ui.cc,v 1.2 2025/05/16 16:08:20 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/about/about_ui.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/webui/about/about_ui.cc
@@ -496,7 +496,7 @@ std::string ChromeURLs(content::BrowserC
   return html;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data,
@@ -538,7 +538,7 @@ TermsUIConfig::TermsUIConfig()
     : AboutUIConfigBase(chrome::kChromeUITermsHost) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 LinuxProxyConfigUI::LinuxProxyConfigUI()
     : AboutUIConfigBase(chrome::kChromeUILinuxProxyConfigHost) {}
 #endif
@@ -590,7 +590,7 @@ void AboutUIHTMLSource::StartDataRequest
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
