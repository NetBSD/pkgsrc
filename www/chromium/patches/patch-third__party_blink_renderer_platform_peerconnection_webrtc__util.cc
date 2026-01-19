$NetBSD: patch-third__party_blink_renderer_platform_peerconnection_webrtc__util.cc,v 1.4 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/peerconnection/webrtc_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/peerconnection/webrtc_util.cc
@@ -23,7 +23,7 @@
 namespace blink {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Enables H.264 CBP encode acceleration.
 BASE_FEATURE(kPlatformH264CbpEncoding,
 #if BUILDFLAG(IS_WIN)
@@ -126,7 +126,7 @@ ConvertToOptionalTimeDelta(std::optional
 bool PLATFORM_EXPORT
 IsH264ConstrainedBaselineProfileAvailableForAcceleratedEncoder() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kPlatformH264CbpEncoding);
 #else
   return false;
