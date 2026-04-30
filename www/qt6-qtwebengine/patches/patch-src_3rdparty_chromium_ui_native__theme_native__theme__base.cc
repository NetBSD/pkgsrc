$NetBSD: patch-src_3rdparty_chromium_ui_native__theme_native__theme__base.cc,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -242,7 +242,7 @@ void NativeThemeBase::Paint(cc::PaintCan
                     std::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         std::get<FrameTopAreaExtraParams>(extra), color_scheme);
