$NetBSD: patch-src_3rdparty_chromium_ui_views_test_ui__controls__factory__desktop__aura__ozone.cc,v 1.1 2025/12/21 09:38:50 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -237,7 +237,7 @@ bool SendMouseClick(MouseButton type, gf
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
