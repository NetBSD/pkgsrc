$NetBSD: patch-third__party_blink_renderer_modules_media_audio_audio__device__factory.cc,v 1.19 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/media/audio/audio_device_factory.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/blink/renderer/modules/media/audio/audio_device_factory.cc
@@ -33,7 +33,7 @@ namespace {
 // Set when the default factory is overridden.
 AudioDeviceFactory* g_factory_override = nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
 // In this case we will time out, to avoid renderer hang forever waiting for
