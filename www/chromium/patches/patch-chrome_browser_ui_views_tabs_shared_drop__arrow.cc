$NetBSD: patch-chrome_browser_ui_views_tabs_shared_drop__arrow.cc,v 1.6 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/shared/drop_arrow.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/shared/drop_arrow.cc
@@ -81,7 +81,7 @@ DropArrow::~DropArrow() {
 
 // static
 void DropArrow::MaybeAdjustDisplayBounds(gfx::Rect& display_bounds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, `GetBoundsInScreen` returns coordinates relative to the browser
   // window (plus shadow elevation outsets) rather than the screen. To handle
   // this, we adjust the display bounds by the difference between the drop arrow
