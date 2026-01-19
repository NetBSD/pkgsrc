$NetBSD: patch-ui_base_test_ui__controls.h,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/test/ui_controls.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/base/test/ui_controls.h
@@ -191,7 +191,7 @@ bool SendTouchEventsNotifyWhenDone(int a
                                    base::OnceClosure task);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Forces the platform implementation to use screen coordinates, even if they're
 // not really available, the next time that ui_controls::SendMouseMove() or
 // ui_controls::SendMouseMoveNotifyWhenDone() is called, or some other method
