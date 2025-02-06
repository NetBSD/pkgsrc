$NetBSD: patch-content_utility_utility__blink__platform__with__sandbox__support__impl.h,v 1.1 2025/02/06 09:58:08 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -33,7 +33,7 @@ class UtilityBlinkPlatformWithSandboxSup
   blink::WebSandboxSupport* GetSandboxSupport() override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
