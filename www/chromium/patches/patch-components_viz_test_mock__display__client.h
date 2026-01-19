$NetBSD: patch-components_viz_test_mock__display__client.h,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/test/mock_display_client.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/viz/test/mock_display_client.h
@@ -45,7 +45,7 @@ class MockDisplayClient : public mojom::
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
