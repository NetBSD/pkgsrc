$NetBSD: patch-media_base_audio__latency.cc,v 1.3 2025/07/07 09:23:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/audio_latency.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ media/base/audio_latency.cc
@@ -147,7 +147,7 @@ int AudioLatency::GetRtcBufferSize(int s
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
