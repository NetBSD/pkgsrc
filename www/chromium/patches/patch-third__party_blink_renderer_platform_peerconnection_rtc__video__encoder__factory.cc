$NetBSD: patch-third__party_blink_renderer_platform_peerconnection_rtc__video__encoder__factory.cc,v 1.8 2025/10/16 19:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc
@@ -36,7 +36,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables H.264 CBP encode acceleration.
 BASE_FEATURE(PlatformH264CbpEncoding,
 #if BUILDFLAG(IS_WIN)
@@ -327,7 +327,7 @@ SupportedFormats GetSupportedFormatsInte
       supported_formats.profiles.push_back(profile.profile);
       supported_formats.sdp_formats.push_back(std::move(*format));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       const bool kShouldAddH264Cbp =
           base::FeatureList::IsEnabled(kPlatformH264CbpEncoding) &&
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
