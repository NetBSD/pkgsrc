$NetBSD: patch-third__party_blink_renderer_modules_peerconnection_rtc__data__channel.cc,v 1.7 2025/09/12 16:02:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -538,6 +538,7 @@ void RTCDataChannel::send(Blob* data, Ex
   pending_messages_.push_back(message);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||
