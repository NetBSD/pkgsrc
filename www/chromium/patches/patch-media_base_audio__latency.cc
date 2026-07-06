$NetBSD: patch-media_base_audio__latency.cc,v 1.22 2026/07/06 13:06:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/audio_latency.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ media/base/audio_latency.cc
@@ -110,7 +110,7 @@ int AudioLatency::GetRtcBufferSize(int s
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
