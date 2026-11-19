$NetBSD: patch-gpu_ipc_client_shared__image__interface__proxy.cc,v 1.1 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/client/shared_image_interface_proxy.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ gpu/ipc/client/shared_image_interface_proxy.cc
@@ -261,7 +261,7 @@ Mailbox SharedImageInterfaceProxy::Creat
   // TODO(kylechar): Verify buffer_handle works for size+format.
   auto mailbox = Mailbox::Generate();
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (host_->client_type() == viz::mojom::GpuClientType::kRenderer) {
     // Only valid client from renderer on ChromeOS and Linux is VideoCapture,
     // that supposed to produce linear buffers.
