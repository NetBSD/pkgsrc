$NetBSD: patch-chromeos_ash_components_mojo__proxy_mojo__core_core_embedder_embedder.cc,v 1.1 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromeos/ash/components/mojo_proxy/mojo_core/core/embedder/embedder.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/embedder/embedder.cc
@@ -37,7 +37,7 @@
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/node_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/channel_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
@@ -79,7 +79,7 @@ void InitFeatures() {
   CHECK(base::FeatureList::GetInstance());
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(MOJO_LEGACY_USE_APPLE_CHANNEL)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   bool shared_mem_enabled = base::FeatureList::IsEnabled(kMojoUseEventFd);
   int num_pages = kMojoUseEventFdPages.Get();
   if (num_pages < 0) {
