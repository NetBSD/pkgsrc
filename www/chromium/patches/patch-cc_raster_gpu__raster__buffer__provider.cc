$NetBSD: patch-cc_raster_gpu__raster__buffer__provider.cc,v 1.1 2026/11/19 19:45:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- cc/raster/gpu_raster_buffer_provider.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ cc/raster/gpu_raster_buffer_provider.cc
@@ -106,7 +106,7 @@ GpuRasterBufferProvider::GpuRasterBuffer
       pending_raster_queries_(pending_raster_queries),
       raster_metric_probability_(raster_metric_probability),
       is_using_dmsaa_(
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
           true
 #else
           false
