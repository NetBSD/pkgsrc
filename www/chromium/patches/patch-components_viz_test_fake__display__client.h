$NetBSD: patch-components_viz_test_fake__display__client.h,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/test/fake_display_client.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/viz/test/fake_display_client.h
@@ -36,7 +36,7 @@ class FakeDisplayClient : public mojom::
   void AddChildWindowToBrowser(gpu::SurfaceHandle child_window) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
