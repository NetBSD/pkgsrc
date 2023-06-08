$NetBSD: patch-src_3rdparty_chromium_media_filters_media__file__checker.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 from archlinux

--- src/3rdparty/chromium/media/filters/media_file_checker.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/media_file_checker.cc
@@ -68,7 +68,7 @@ bool MediaFileChecker::Start(base::TimeD
       auto context = AVStreamToAVCodecContext(format_context->streams[i]);
       if (!context)
         continue;
-      AVCodec* codec = avcodec_find_decoder(cp->codec_id);
+      const AVCodec* codec = avcodec_find_decoder(cp->codec_id);
       if (codec && avcodec_open2(context.get(), codec, nullptr) >= 0) {
         auto loop = std::make_unique<FFmpegDecodingLoop>(context.get());
         stream_contexts[i] = {std::move(context), std::move(loop)};
