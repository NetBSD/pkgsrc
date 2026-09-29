$NetBSD: patch-chrome_browser_ui_webui_about_about__ui.cc,v 1.27 2026/09/29 07:42:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/about/about_ui.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/webui/about/about_ui.cc
@@ -406,7 +406,7 @@ using about_ui::AppendHeader;
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data,
@@ -436,7 +436,7 @@ TermsUIConfig::TermsUIConfig()
     : AboutUIConfigBase(chrome::kChromeUITermsHost) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 LinuxProxyConfigUI::LinuxProxyConfigUI()
     : AboutUIConfigBase(chrome::kChromeUILinuxProxyConfigHost) {}
 #endif
@@ -482,7 +482,7 @@ void AboutUIHTMLSource::StartDataRequest
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
