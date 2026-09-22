$NetBSD: patch-components_viz_test_mock__display__client.h,v 1.26 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/test/mock_display_client.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/viz/test/mock_display_client.h
@@ -45,7 +45,7 @@ class MockDisplayClient : public mojom::
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
