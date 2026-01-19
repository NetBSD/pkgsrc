$NetBSD: patch-components_viz_host_gpu__host__impl.cc,v 1.13 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/host/gpu_host_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/viz/host/gpu_host_impl.cc
@@ -158,7 +158,7 @@ GpuHostImpl::GpuHostImpl(Delegate* deleg
       mojom::GpuServiceCreationParams::New();
 #if BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux has an issue when running in single-process mode wherein
   // GetPlatformRuntimeProperties() browser-side calls can have a data race with
   // in-process GPU service initialization. The call to
