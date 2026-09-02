$NetBSD: patch-remoting_host_peer__session__impl.cc,v 1.1 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/peer_session_impl.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/peer_session_impl.cc
@@ -307,7 +307,7 @@ void PeerSessionImpl::NotifyClientResolu
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
