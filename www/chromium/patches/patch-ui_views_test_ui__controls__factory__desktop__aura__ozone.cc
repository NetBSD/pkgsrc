$NetBSD: patch-ui_views_test_ui__controls__factory__desktop__aura__ozone.cc,v 1.6 2025/09/08 13:24:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -237,7 +237,7 @@ bool SendMouseClick(MouseButton type, gf
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
