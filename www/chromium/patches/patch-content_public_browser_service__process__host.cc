$NetBSD: patch-content_public_browser_service__process__host.cc,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/browser/service_process_host.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/public/browser/service_process_host.cc
@@ -71,7 +71,7 @@ ServiceProcessHost::Options::WithPreload
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithGpuClient(
     base::PassKey<ServiceProcessHostGpuClient> passkey) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   allow_gpu_client = true;
 #endif
   return *this;
