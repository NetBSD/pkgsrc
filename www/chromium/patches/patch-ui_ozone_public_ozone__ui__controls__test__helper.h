$NetBSD: patch-ui_ozone_public_ozone__ui__controls__test__helper.h,v 1.9 2025/11/20 08:36:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/public/ozone_ui_controls_test_helper.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ ui/ozone/public/ozone_ui_controls_test_helper.h
@@ -62,7 +62,7 @@ class OzoneUIControlsTestHelper {
   // aura::Window.
   virtual bool MustUseUiControlsForMoveCursorTo() = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual void ForceUseScreenCoordinatesOnce();
 #endif
 };
