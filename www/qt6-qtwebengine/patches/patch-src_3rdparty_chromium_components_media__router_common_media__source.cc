$NetBSD: patch-src_3rdparty_chromium_components_media__router_common_media__source.cc,v 1.1 2025/12/21 09:38:23 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/media_router/common/media_source.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/media_router/common/media_source.cc
@@ -57,7 +57,7 @@ bool IsSystemAudioCaptureSupported() {
   if (!media::IsSystemLoopbackCaptureSupported()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
