$NetBSD: patch-src_3rdparty_chromium_ui_views_window_frame__background.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/views/window/frame_background.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/views/window/frame_background.cc
@@ -99,7 +99,7 @@ void FrameBackground::PaintMaximized(gfx
                                      const View* view) const {
 // Fill the top with the frame color first so we have a constant background
 // for areas not covered by the theme image.
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   auto* native_theme = view->GetNativeTheme();
   ui::NativeTheme::ExtraParams params;
