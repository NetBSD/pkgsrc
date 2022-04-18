$NetBSD: patch-src_3rdparty_chromium_ui_base_webui_web__ui__util.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/webui/web_ui_util.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/webui/web_ui_util.cc
@@ -232,7 +232,7 @@ std::string GetFontFamily() {
 
 // TODO(dnicoara) Remove Ozone check when PlatformFont support is introduced
 // into Ozone: crbug.com/320050
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!features::IsUsingOzonePlatform()) {
     font_family = ui::ResourceBundle::GetSharedInstance()
                       .GetFont(ui::ResourceBundle::BaseFont)
