$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_modules_media_audio_web__audio__device__factory.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc
@@ -32,7 +32,7 @@ WebAudioDeviceFactory* WebAudioDeviceFac
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
