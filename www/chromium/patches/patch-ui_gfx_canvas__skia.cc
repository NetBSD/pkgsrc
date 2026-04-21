$NetBSD: patch-ui_gfx_canvas__skia.cc,v 1.18 2026/04/21 15:21:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/canvas_skia.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/gfx/canvas_skia.cc
@@ -219,7 +219,7 @@ void Canvas::DrawStringRectWithFlags(std
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
