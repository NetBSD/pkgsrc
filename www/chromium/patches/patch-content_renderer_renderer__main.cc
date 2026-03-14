$NetBSD: patch-content_renderer_renderer__main.cc,v 1.1 2026/03/14 12:40:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_main.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ content/renderer/renderer_main.cc
@@ -196,7 +196,7 @@ int RendererMain(MainFunctionParams para
 
   InitializeSkia();
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   // On Linux, Windows, and ChromeOS, the font manager is overridden or
   // specially handled in RendererBlinkPlatformImpl(). On other platforms,
   // initialise the default one on a thread pool, to avoid blocking on it later.
