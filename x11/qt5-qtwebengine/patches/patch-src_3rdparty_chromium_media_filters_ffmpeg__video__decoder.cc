$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__video__decoder.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 from archlinux

--- src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.cc
@@ -391,7 +391,7 @@ bool FFmpegVideoDecoder::ConfigureDecode
   if (decode_nalus_)
     codec_context_->flags2 |= AV_CODEC_FLAG2_CHUNKS;
 
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (!codec || avcodec_open2(codec_context_.get(), codec, NULL) < 0) {
     ReleaseFFmpegResources();
     return false;
