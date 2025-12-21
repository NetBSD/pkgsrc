$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_about_about__ui.h,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/about/about_ui.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/about/about_ui.h
@@ -50,7 +50,7 @@ class TermsUIConfig : public AboutUIConf
 };
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // chrome://linux-proxy-config
 class LinuxProxyConfigUI : public AboutUIConfigBase {
  public:
