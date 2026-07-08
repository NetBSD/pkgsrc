$NetBSD: patch-components_media__router_common_media__source.cc,v 1.23 2026/07/08 13:42:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/media_router/common/media_source.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/media_router/common/media_source.cc
@@ -68,7 +68,7 @@ bool IsSystemAudioCaptureSupported() {
 #if BUILDFLAG(IS_MAC)
   return media::IsMacSckSystemLoopbackCaptureSupported() ||
          base::FeatureList::IsEnabled(media::kMacCatapLoopbackAudioForCast);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
 #else
   return true;
