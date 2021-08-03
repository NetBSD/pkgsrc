$NetBSD: patch-src_3rdparty_chromium_content_utility_utility__blink__platform__with__sandbox__support__impl.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -11,7 +11,7 @@
 #include "build/build_config.h"
 #include "third_party/blink/public/platform/platform.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -33,10 +33,10 @@ class UtilityBlinkPlatformWithSandboxSup
   blink::WebSandboxSupport* GetSandboxSupport() override;
 
  private:
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
