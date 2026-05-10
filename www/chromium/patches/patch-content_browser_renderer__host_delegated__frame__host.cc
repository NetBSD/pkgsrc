$NetBSD: patch-content_browser_renderer__host_delegated__frame__host.cc,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/delegated_frame_host.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/renderer_host/delegated_frame_host.cc
@@ -346,7 +346,7 @@ void DelegatedFrameHost::EmbedSurface(
 
   if (!primary_surface_id ||
       primary_surface_id->local_surface_id() != local_surface_id_) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // On Windows, Linux, and macOS, we would like to produce new content as
     // soon as possible or the OS will create an additional black gutter.
     // Until we can block resize on surface synchronization on these
