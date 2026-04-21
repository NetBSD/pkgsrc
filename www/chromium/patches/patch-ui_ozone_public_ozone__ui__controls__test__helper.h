$NetBSD: patch-ui_ozone_public_ozone__ui__controls__test__helper.h,v 1.17 2026/04/21 15:21:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/public/ozone_ui_controls_test_helper.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/ozone/public/ozone_ui_controls_test_helper.h
@@ -62,7 +62,7 @@ class OzoneUIControlsTestHelper {
   // aura::Window.
   virtual bool MustUseUiControlsForMoveCursorTo() = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual void ForceUseScreenCoordinatesOnce();
 #endif
 };
