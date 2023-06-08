$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_video__coding_codecs_h264_h264__decoder__impl.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 from archlinux

--- src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -203,7 +203,7 @@ int32_t H264DecoderImpl::InitDecode(cons
   // a pointer |this|.
   av_context_->opaque = this;
 
-  AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
     // This is an indication that FFmpeg has not been initialized or it has not
     // been compiled/initialized with the correct set of codecs.
