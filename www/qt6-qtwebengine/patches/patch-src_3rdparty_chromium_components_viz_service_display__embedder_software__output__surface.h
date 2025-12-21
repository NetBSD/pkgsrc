$NetBSD: patch-src_3rdparty_chromium_components_viz_service_display__embedder_software__output__surface.h,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/viz/service/display_embedder/software_output_surface.h
@@ -41,7 +41,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -59,7 +59,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
   base::TimeTicks refresh_timebase_;
   base::TimeDelta refresh_interval_ = BeginFrameArgs::DefaultInterval();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
