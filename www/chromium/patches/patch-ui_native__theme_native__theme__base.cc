$NetBSD: patch-ui_native__theme_native__theme__base.cc,v 1.7 2025/09/12 16:02:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/native_theme_base.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/native_theme/native_theme_base.cc
@@ -242,7 +242,7 @@ void NativeThemeBase::Paint(cc::PaintCan
                     std::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         std::get<FrameTopAreaExtraParams>(extra), color_scheme);
