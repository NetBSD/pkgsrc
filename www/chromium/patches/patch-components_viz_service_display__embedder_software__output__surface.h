$NetBSD: patch-components_viz_service_display__embedder_software__output__surface.h,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/software_output_surface.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -40,7 +40,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -58,7 +58,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
   base::TimeTicks refresh_timebase_;
   base::TimeDelta refresh_interval_ = BeginFrameArgs::DefaultInterval();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
