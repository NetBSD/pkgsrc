$NetBSD: patch-src_3rdparty_chromium_media_filters_audio__file__reader.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 - from archlinux

--- src/3rdparty/chromium/media/filters/audio_file_reader.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/audio_file_reader.cc
@@ -85,7 +85,7 @@ bool AudioFileReader::OpenDemuxer() {
 }
 
 bool AudioFileReader::OpenDecoder() {
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (codec) {
     // MP3 decodes to S16P which we don't support, tell it to use S16 instead.
     if (codec_context_->sample_fmt == AV_SAMPLE_FMT_S16P)
