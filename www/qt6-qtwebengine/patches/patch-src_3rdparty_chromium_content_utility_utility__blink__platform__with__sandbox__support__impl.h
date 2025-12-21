$NetBSD: patch-src_3rdparty_chromium_content_utility_utility__blink__platform__with__sandbox__support__impl.h,v 1.1 2025/12/21 09:38:28 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -34,7 +34,7 @@ class UtilityBlinkPlatformWithSandboxSup
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
