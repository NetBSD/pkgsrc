$NetBSD: patch-src_3rdparty_chromium_ui_native__theme_native__theme__base.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -239,7 +239,7 @@ void NativeThemeBase::Paint(cc::PaintCan
                     absl::get<ButtonExtraParams>(extra), color_scheme,
                     accent_color_opaque);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         absl::get<FrameTopAreaExtraParams>(extra),
