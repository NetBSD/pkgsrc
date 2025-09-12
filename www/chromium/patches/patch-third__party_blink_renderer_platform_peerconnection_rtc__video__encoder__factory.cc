$NetBSD: patch-third__party_blink_renderer_platform_peerconnection_rtc__video__encoder__factory.cc,v 1.7 2025/09/12 16:02:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/blink/renderer/platform/peerconnection/rtc_video_encoder_factory.cc
@@ -324,12 +324,12 @@ SupportedFormats GetSupportedFormatsInte
       supported_formats.profiles.push_back(profile.profile);
       supported_formats.sdp_formats.push_back(std::move(*format));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_WIN)
       const bool kShouldAddH264Cbp =
           base::FeatureList::IsEnabled(kMediaFoundationH264CbpEncoding) &&
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       const bool kShouldAddH264Cbp =
           profile.profile == media::VideoCodecProfile::H264PROFILE_BASELINE;
 #endif
