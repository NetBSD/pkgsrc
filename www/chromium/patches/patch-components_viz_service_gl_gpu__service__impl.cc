$NetBSD: patch-components_viz_service_gl_gpu__service__impl.cc,v 1.2 2025/07/25 16:17:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -515,7 +515,7 @@ void GpuServiceImpl::InitializeWithHostI
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1351,7 +1351,7 @@ bool GpuServiceImpl::OnBeginFrameDerived
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
   auto buffer_format = gfx::BufferFormat::YUV_420_BIPLANAR;
