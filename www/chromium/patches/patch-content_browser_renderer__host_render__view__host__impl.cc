$NetBSD: patch-content_browser_renderer__host_render__view__host__impl.cc,v 1.21 2026/06/08 13:12:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_view_host_impl.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -266,7 +266,7 @@ void RenderViewHostImpl::GetPlatformSpec
   GetFontInfo(gfx::win::SystemFont::kStatus, &prefs->status_font_family_name,
               &prefs->status_font_height);
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
