$NetBSD: patch-content_utility_utility__blink__platform__with__sandbox__support__impl.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/utility_blink_platform_with_sandbox_support_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.cc
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #elif BUILDFLAG(IS_WIN)
 #include "content/child/child_process_sandbox_support_impl_win.h"
@@ -19,7 +19,7 @@ namespace content {
 
 UtilityBlinkPlatformWithSandboxSupportImpl::
     UtilityBlinkPlatformWithSandboxSupportImpl() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -40,7 +40,7 @@ UtilityBlinkPlatformWithSandboxSupportIm
 blink::WebSandboxSupport*
 UtilityBlinkPlatformWithSandboxSupportImpl::GetSandboxSupport() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
