$NetBSD: patch-third__party_blink_renderer_platform_peerconnection_webrtc__util.cc,v 1.8 2026/04/21 15:21:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/peerconnection/webrtc_util.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/blink/renderer/platform/peerconnection/webrtc_util.cc
@@ -23,7 +23,7 @@
 namespace blink {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Enables H.264 CBP encode acceleration.
 BASE_FEATURE(kPlatformH264CbpEncoding,
 #if BUILDFLAG(IS_WIN)
@@ -123,7 +123,7 @@ ConvertToOptionalTimeDelta(std::optional
 bool PLATFORM_EXPORT
 IsH264ConstrainedBaselineProfileAvailableForAcceleratedEncoder() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kPlatformH264CbpEncoding);
 #else
   return false;
