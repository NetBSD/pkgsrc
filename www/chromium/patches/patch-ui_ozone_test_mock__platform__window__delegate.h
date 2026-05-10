$NetBSD: patch-ui_ozone_test_mock__platform__window__delegate.h,v 1.19 2026/05/10 15:30:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/test/mock_platform_window_delegate.h.orig	2026-04-28 23:05:57.000000000 +0200
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
