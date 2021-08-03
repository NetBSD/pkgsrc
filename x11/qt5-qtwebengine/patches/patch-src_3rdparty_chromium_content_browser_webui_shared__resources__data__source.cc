$NetBSD: patch-src_3rdparty_chromium_content_browser_webui_shared__resources__data__source.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/webui/shared_resources_data_source.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/browser/webui/shared_resources_data_source.cc
@@ -131,7 +131,7 @@ const std::map<int, std::string> CreateM
          "mojo/mojo/public/mojom/base/text_direction.mojom.html"},
         {IDR_MOJO_TEXT_DIRECTION_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/text_direction.mojom-lite.js"},
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         {IDR_MOJO_TIME_MOJOM_HTML,
          "mojo/mojo/public/mojom/base/time.mojom.html"},
         {IDR_MOJO_TIME_MOJOM_LITE_JS,
