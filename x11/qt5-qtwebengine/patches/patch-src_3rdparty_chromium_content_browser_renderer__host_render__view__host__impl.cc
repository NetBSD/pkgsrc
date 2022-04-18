$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__view__host__impl.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_view_host_impl.cc
@@ -278,7 +278,7 @@ void RenderViewHostImpl::GetPlatformSpec
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #elif defined(OS_FUCHSIA)
   // Make Blink's "focus ring" invisible. The focus ring is a hairline border
