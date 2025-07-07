$NetBSD: patch-content_browser_audio_audio__service.cc,v 1.3 2025/07/07 09:23:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/audio/audio_service.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/browser/audio/audio_service.cc
@@ -33,7 +33,7 @@
 #if BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS)
 #include "ui/display/util/edid_parser.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/display_util.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -201,7 +201,7 @@ audio::mojom::AudioService& GetAudioServ
         ->PostTaskAndReplyWithResult(
             FROM_HERE, base::BindOnce(&ScanEdidBitstreams),
             base::BindOnce(&LaunchAudioService, std::move(receiver)));
-#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(ENABLE_PASSTHROUGH_AUDIO_CODECS) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     LaunchAudioService(
         std::move(receiver),
         ConvertEdidBitstreams(display::DisplayUtil::GetAudioFormats()));
