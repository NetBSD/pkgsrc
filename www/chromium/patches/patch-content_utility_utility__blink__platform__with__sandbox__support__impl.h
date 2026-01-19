$NetBSD: patch-content_utility_utility__blink__platform__with__sandbox__support__impl.h,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -34,7 +34,7 @@ class UtilityBlinkPlatformWithSandboxSup
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
