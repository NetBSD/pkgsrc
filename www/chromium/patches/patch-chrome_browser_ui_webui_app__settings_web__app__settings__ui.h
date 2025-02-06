$NetBSD: patch-chrome_browser_ui_webui_app__settings_web__app__settings__ui.h,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/app_settings/web_app_settings_ui.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/app_settings/web_app_settings_ui.h
@@ -14,13 +14,13 @@
 #include "ui/webui/mojo_web_ui_controller.h"
 #include "ui/webui/resources/cr_components/app_management/app_management.mojom-forward.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/webui_url_constants.h"
 #include "content/public/browser/webui_config.h"
 #include "content/public/common/url_constants.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WebAppSettingsUI;
 
 class WebAppSettingsUIConfig
