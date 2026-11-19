$NetBSD: patch-gpu_ipc_client_client__shared__image__interface.cc,v 1.1 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/client/client_shared_image_interface.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ gpu/ipc/client/client_shared_image_interface.cc
@@ -168,7 +168,7 @@ scoped_refptr<ClientSharedImage> ClientS
   CHECK(!si_info.format.PrefersExternalSampler()) << si_info.format.ToString();
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Only valid client from renderer on ChromeOS and Linux is VideoCapture, that
   // uses SCANOUT_VEA_CPU_READ.
   if (gpu_channel_->client_type() == viz::mojom::GpuClientType::kRenderer) {
