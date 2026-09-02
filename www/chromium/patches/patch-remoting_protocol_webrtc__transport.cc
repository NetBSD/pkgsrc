$NetBSD: patch-remoting_protocol_webrtc__transport.cc,v 1.5 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/protocol/webrtc_transport.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/protocol/webrtc_transport.cc
@@ -1194,7 +1194,7 @@ void WebrtcTransport::SendOffer() {
   // `recvonly` if microphone remoting is not enabled. Only Linux hosts support
   // audio injection (microphone remoting).
   // TODO: crbug.com/513327818 - Hook this up with AudioInjector::IsSupported().
-  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX);
+  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD);
   options.ice_restart = want_ice_restart_;
   peer_connection()->CreateOffer(
       CreateSessionDescriptionObserver::Create(
