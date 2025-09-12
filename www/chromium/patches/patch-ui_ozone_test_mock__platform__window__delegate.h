$NetBSD: patch-ui_ozone_test_mock__platform__window__delegate.h,v 1.7 2025/09/12 16:02:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/test/mock_platform_window_delegate.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/ozone/test/mock_platform_window_delegate.h
@@ -35,7 +35,7 @@ class MockPlatformWindowDelegate : publi
   MOCK_METHOD2(OnWindowStateChanged,
                void(PlatformWindowState old_state,
                     PlatformWindowState new_state));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MOCK_METHOD1(OnWindowTiledStateChanged,
                void(WindowTiledEdges new_tiled_edges));
 #endif
