$NetBSD: patch-chrome_browser_ui_views_tabs_shared_drop__arrow.cc,v 1.3 2026/06/08 13:12:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/shared/drop_arrow.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/ui/views/tabs/shared/drop_arrow.cc
@@ -76,7 +76,7 @@ DropArrow::~DropArrow() {
 
 // static
 void DropArrow::MaybeAdjustDisplayBounds(gfx::Rect& display_bounds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, `GetBoundsInScreen` returns coordinates relative to the browser
   // window (plus shadow elevation outsets) rather than the screen. To handle
   // this, we adjust the display bounds by the difference between the drop arrow
