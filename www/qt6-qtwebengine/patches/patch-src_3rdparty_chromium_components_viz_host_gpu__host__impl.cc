$NetBSD: patch-src_3rdparty_chromium_components_viz_host_gpu__host__impl.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/viz/host/gpu_host_impl.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/viz/host/gpu_host_impl.cc
@@ -135,7 +135,7 @@ GpuHostImpl::GpuHostImpl(Delegate* deleg
       mojom::GpuServiceCreationParams::New();
 #if BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux has an issue when running in single-process mode wherein
   // GetPlatformRuntimeProperties() browser-side calls can have a data race with
   // in-process GPU service initialization. The call to
