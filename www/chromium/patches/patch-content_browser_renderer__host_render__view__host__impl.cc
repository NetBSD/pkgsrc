$NetBSD: patch-content_browser_renderer__host_render__view__host__impl.cc,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_view_host_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -274,7 +274,7 @@ void RenderViewHostImpl::GetPlatformSpec
       display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::GetScreenWin()->GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
