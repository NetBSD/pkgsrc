$NetBSD: patch-components_viz_service_gl_gpu__service__impl.cc,v 1.13 2026/02/15 09:04:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.cc
@@ -472,7 +472,7 @@ void GpuServiceImpl::InitializeWithHostI
 
   mojo::Remote<mojom::GpuHost> gpu_host(std::move(pending_gpu_host));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gpu_extra_info_.is_gmb_nv12_supported = IsGMBNV12Supported();
 #endif
 
@@ -1230,7 +1230,7 @@ bool GpuServiceImpl::OnBeginFrameDerived
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuServiceImpl::IsGMBNV12Supported() {
   CHECK(main_runner_->BelongsToCurrentThread());
 
