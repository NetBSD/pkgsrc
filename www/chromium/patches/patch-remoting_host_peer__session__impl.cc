$NetBSD: patch-remoting_host_peer__session__impl.cc,v 1.2 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/peer_session_impl.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/host/peer_session_impl.cc
@@ -299,7 +299,7 @@ void PeerSessionImpl::NotifyClientResolu
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
