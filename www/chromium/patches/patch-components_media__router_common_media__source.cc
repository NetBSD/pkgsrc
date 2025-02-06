$NetBSD: patch-components_media__router_common_media__source.cc,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/media_router/common/media_source.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/media_router/common/media_source.cc
@@ -57,7 +57,7 @@ bool IsSystemAudioCaptureSupported() {
   if (!media::IsSystemLoopbackCaptureSupported()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
