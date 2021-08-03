$NetBSD: patch-src_3rdparty_chromium_ui_native__theme_native__theme__base.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/native_theme/native_theme_base.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ src/3rdparty/chromium/ui/native_theme/native_theme_base.cc
@@ -255,7 +255,7 @@ void NativeThemeBase::Paint(cc::PaintCan
     case kCheckbox:
       PaintCheckbox(canvas, state, rect, extra.button, color_scheme);
       break;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area,
                         color_scheme);
