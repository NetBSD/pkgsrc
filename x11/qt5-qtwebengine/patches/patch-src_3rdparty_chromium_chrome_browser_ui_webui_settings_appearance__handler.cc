$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_settings_appearance__handler.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -27,7 +27,7 @@ void AppearanceHandler::RegisterMessages
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseDefaultTheme,
                           base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -39,7 +39,7 @@ void AppearanceHandler::HandleUseDefault
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
