$NetBSD: patch-components_viz_host_host__display__client.cc,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/host/host_display_client.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/viz/host/host_display_client.cc
@@ -65,7 +65,7 @@ void HostDisplayClient::AddChildWindowTo
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
