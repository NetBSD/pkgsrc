$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__audio__decoder.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 - from archlinux

--- src/3rdparty/chromium/media/filters/ffmpeg_audio_decoder.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_audio_decoder.cc
@@ -329,7 +329,7 @@ bool FFmpegAudioDecoder::ConfigureDecode
     }
   }
 
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (!codec ||
       avcodec_open2(codec_context_.get(), codec, &codec_options) < 0) {
     DLOG(ERROR) << "Could not initialize audio decoder: "
