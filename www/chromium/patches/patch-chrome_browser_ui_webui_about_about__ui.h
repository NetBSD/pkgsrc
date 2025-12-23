$NetBSD: patch-chrome_browser_ui_webui_about_about__ui.h,v 1.13 2025/12/23 13:22:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/about/about_ui.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/ui/webui/about/about_ui.h
@@ -43,7 +43,7 @@ class TermsUIConfig : public AboutUIConf
 };
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // chrome://linux-proxy-config
 class LinuxProxyConfigUI : public AboutUIConfigBase {
  public:
