$NetBSD: patch-chromecast_browser_cast__content__browser__client.cc,v 1.6 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromecast/browser/cast_content_browser_client.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chromecast/browser/cast_content_browser_client.cc
@@ -433,7 +433,7 @@ void CastContentBrowserClient::AppendExt
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Necessary for accelerated 2d canvas.  By default on Linux, Chromium
     // assumes GLES2 contexts can be lost to a power-save mode, which breaks GPU
     // canvas apps.
