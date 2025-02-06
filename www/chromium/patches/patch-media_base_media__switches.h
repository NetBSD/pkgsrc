$NetBSD: patch-media_base_media__switches.h,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/media_switches.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/base/media_switches.h
@@ -44,7 +44,7 @@ MEDIA_EXPORT extern const char kDisableB
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
 #endif
@@ -333,13 +333,26 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlatf
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
@@ -353,7 +366,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kSuspe
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUnifiedAutoplay);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseAndroidOverlayForSecureOnly);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseFakeDeviceForMediaStream);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoEncodeLinux);
@@ -374,7 +387,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp9SModeHWEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVSyncMjpegDecoding);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVideoBlitColorAccuracy);
@@ -511,7 +524,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOu
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseGTFOOutOfProcessVideoDecoding);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
