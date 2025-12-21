$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_modules_media_audio_audio__device__factory.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/audio_device_factory.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/audio_device_factory.cc
@@ -34,7 +34,7 @@ namespace {
 // Set when the default factory is overridden.
 AudioDeviceFactory* g_factory_override = nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
