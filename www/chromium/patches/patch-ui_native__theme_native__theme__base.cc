$NetBSD: patch-ui_native__theme_native__theme__base.cc,v 1.9 2025/11/04 14:55:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/native_theme/native_theme_base.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ ui/native_theme/native_theme_base.cc
@@ -168,7 +168,7 @@ void NativeThemeBase::PaintImpl(cc::Pain
                     std::get<ButtonExtraParams>(extra_params), dark_mode,
                     contrast, accent_color);
       break;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect,
                         std::get<FrameTopAreaExtraParams>(extra_params));
