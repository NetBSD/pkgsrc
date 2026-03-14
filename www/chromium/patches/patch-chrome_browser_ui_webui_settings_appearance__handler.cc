$NetBSD: patch-chrome_browser_ui_webui_settings_appearance__handler.cc,v 1.16 2026/03/14 12:40:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -33,7 +33,7 @@ void AppearanceHandler::RegisterMessages
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
                           base::Unretained(this), ui::SystemTheme::kDefault));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useGtkTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
