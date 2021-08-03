$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__view__host__impl.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc
@@ -230,7 +230,7 @@ void RenderViewHostImpl::GetPlatformSpec
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif defined(OS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
