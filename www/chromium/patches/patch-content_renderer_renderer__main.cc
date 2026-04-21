$NetBSD: patch-content_renderer_renderer__main.cc,v 1.3 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_main.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ content/renderer/renderer_main.cc
@@ -180,7 +180,7 @@ int RendererMain(MainFunctionParams para
 
   InitializeSkia();
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   // On Linux, Windows, and ChromeOS, the font manager is overridden or
   // specially handled in RendererBlinkPlatformImpl(). On other platforms,
   // initialise the default one on a thread pool, to avoid blocking on it later.
