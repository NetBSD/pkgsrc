$NetBSD: patch-chrome_browser_renderer__context__menu_render__view__context__menu.cc,v 1.16 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/renderer_context_menu/render_view_context_menu.cc
@@ -284,7 +284,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -5868,7 +5868,7 @@ void RenderViewContextMenu::AppendRevise
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderViewContextMenu::IsLinkToIsolatedWebApp() const {
   // Using `unfiltered_link_url`, because `link_url` is being replaced with
   // about:blank#blocked if the source is a normal site.
