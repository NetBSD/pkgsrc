$NetBSD: patch-src_3rdparty_chromium_media_ffmpeg_ffmpeg__common.h,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 - from archlinux

--- src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.h.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.h
@@ -29,6 +29,7 @@ extern "C" {
 #include <libavformat/avformat.h>
 #include <libavformat/avio.h>
 #include <libavutil/avutil.h>
+#include <libavutil/channel_layout.h>
 #include <libavutil/imgutils.h>
 #include <libavutil/log.h>
 #include <libavutil/mastering_display_metadata.h>
