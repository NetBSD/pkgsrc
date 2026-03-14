$NetBSD: patch-media_capture_video_video__capture__device__client.cc,v 1.16 2026/03/14 12:40:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/video_capture_device_client.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ media/capture/video/video_capture_device_client.cc
@@ -166,7 +166,7 @@ FourccAndFlip GetFourccAndFlipFromPixelF
       CHECK(!is_width_odd && !is_height_odd);
       return {libyuv::FOURCC_UYVY};
     case media::PIXEL_FORMAT_RGB24:
-      if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) {
+      if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
         // Linux RGB24 defines red at lowest byte address,
         // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
         return {libyuv::FOURCC_RAW};
