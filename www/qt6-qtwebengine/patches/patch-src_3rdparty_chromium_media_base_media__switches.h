$NetBSD: patch-src_3rdparty_chromium_media_base_media__switches.h,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/base/media_switches.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/media/base/media_switches.h
@@ -43,7 +43,7 @@ MEDIA_EXPORT extern const char kDisableB
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
 #endif
@@ -338,13 +338,26 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kMedia
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlaybackSpeedButton);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMediaEngagementData);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMetadataSuspend);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAudioIO,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordMediaEngagementScores);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordWebAudioEngagement);
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kResumeBackgroundVideo);
@@ -363,7 +376,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUnifi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseAndroidOverlayForSecureOnly);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseFakeDeviceForMediaStream);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kMediaStreamAccurateDroppedFrameCount);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoEncodeLinux);
@@ -379,7 +392,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp9SModeHWEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVSyncMjpegDecoding);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVideoBlitColorAccuracy);
@@ -497,7 +510,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kBackg
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoDecoding);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
