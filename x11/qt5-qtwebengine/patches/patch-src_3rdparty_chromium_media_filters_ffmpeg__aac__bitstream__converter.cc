$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__aac__bitstream__converter.cc,v 1.1 2025/02/23 18:59:28 markd Exp $

build with ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/ffmpeg_aac_bitstream_converter.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_aac_bitstream_converter.cc
@@ -195,14 +195,15 @@ bool FFmpegAACBitstreamConverter::Conver
   if (!header_generated_ || codec_ != stream_codec_parameters_->codec_id ||
       audio_profile_ != stream_codec_parameters_->profile ||
       sample_rate_index_ != sample_rate_index ||
-      channel_configuration_ != stream_codec_parameters_->channels ||
+      channel_configuration_ !=
+          stream_codec_parameters_->ch_layout.nb_channels ||
       frame_length_ != header_plus_packet_size) {
     header_generated_ =
         GenerateAdtsHeader(stream_codec_parameters_->codec_id,
                            0,  // layer
                            stream_codec_parameters_->profile, sample_rate_index,
                            0,  // private stream
-                           stream_codec_parameters_->channels,
+                           stream_codec_parameters_->ch_layout.nb_channels,
                            0,  // originality
                            0,  // home
                            0,  // copyrighted_stream
@@ -214,7 +215,7 @@ bool FFmpegAACBitstreamConverter::Conver
     codec_ = stream_codec_parameters_->codec_id;
     audio_profile_ = stream_codec_parameters_->profile;
     sample_rate_index_ = sample_rate_index;
-    channel_configuration_ = stream_codec_parameters_->channels;
+    channel_configuration_ = stream_codec_parameters_->ch_layout.nb_channels;
     frame_length_ = header_plus_packet_size;
   }
 
