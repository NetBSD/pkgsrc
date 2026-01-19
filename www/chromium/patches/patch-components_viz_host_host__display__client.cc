$NetBSD: patch-components_viz_host_host__display__client.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/host/host_display_client.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/viz/host/host_display_client.cc
@@ -66,9 +66,9 @@ void HostDisplayClient::AddChildWindowTo
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
-  NOTIMPLEMENTED();
+  NOTREACHED();
 }
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
