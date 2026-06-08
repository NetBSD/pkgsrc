$NetBSD: patch-remoting_host_audio__injector.cc,v 1.1 2026/06/08 13:12:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/audio_injector.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ remoting/host/audio_injector.cc
@@ -8,7 +8,7 @@
 #include "build/build_config.h"
 #include "remoting/proto/audio.pb.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/pipewire_audio_injector.h"
 #endif
 
@@ -26,7 +26,7 @@ void AudioInjector::ProcessAudioPacket(s
 
 // static
 bool AudioInjector::IsSupported() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, we check if PipeWire is available and can be initialized.
   // Note that in multi-process mode, this may return true in the network
   // process because the libraries are loadable, even though the virtual audio
