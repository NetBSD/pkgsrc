$NetBSD: patch-src_3rdparty_chromium_content_ppapi__plugin_ppapi__blink__platform__impl.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "content/child/blink_platform_impl.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -36,11 +36,11 @@ class PpapiBlinkPlatformImpl : public Bl
   blink::WebThemeEngine* ThemeEngine() override;
 
  private:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
