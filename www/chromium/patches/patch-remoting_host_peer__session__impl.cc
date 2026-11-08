$NetBSD: patch-remoting_host_peer__session__impl.cc,v 1.8 2026/11/08 15:39:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/peer_session_impl.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ remoting/host/peer_session_impl.cc
@@ -194,7 +194,7 @@ PeerSessionImpl::PeerSessionImpl(
   // LocalMouseInputMonitorMac filter out an echo of the injected input before
   // it reaches `remote_input_filter_`.
   input_pipeline_.remote_input_filter()->SetExpectLocalEcho(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LocalMouseInputMonitorX11 filters out XTest-injected input before it
   // reaches `remote_input_filter_`. On Wayland, PipewireLocalInputMonitor
   // observes global cursor positions from PipeWire and still relies on echo
@@ -299,7 +299,7 @@ void PeerSessionImpl::NotifyClientResolu
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
