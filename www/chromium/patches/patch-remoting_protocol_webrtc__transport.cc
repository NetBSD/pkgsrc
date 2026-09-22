$NetBSD: patch-remoting_protocol_webrtc__transport.cc,v 1.6 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/protocol/webrtc_transport.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ remoting/protocol/webrtc_transport.cc
@@ -1205,7 +1205,7 @@ void WebrtcTransport::SendOffer() {
   // `recvonly` if microphone remoting is not enabled. Only Linux hosts support
   // audio injection (microphone remoting).
   // TODO: crbug.com/513327818 - Hook this up with AudioInjector::IsSupported().
-  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX);
+  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD);
   options.ice_restart = want_ice_restart_;
   peer_connection()->CreateOffer(
       CreateSessionDescriptionObserver::Create(
