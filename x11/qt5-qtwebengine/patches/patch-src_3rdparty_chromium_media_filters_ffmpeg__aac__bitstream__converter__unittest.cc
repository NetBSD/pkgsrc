$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__aac__bitstream__converter__unittest.cc,v 1.1 2025/02/23 18:59:28 markd Exp $

build with ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/ffmpeg_aac_bitstream_converter_unittest.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_aac_bitstream_converter_unittest.cc
@@ -29,7 +29,7 @@ class FFmpegAACBitstreamConverterTest : 
     memset(&test_parameters_, 0, sizeof(AVCodecParameters));
     test_parameters_.codec_id = AV_CODEC_ID_AAC;
     test_parameters_.profile = FF_PROFILE_AAC_MAIN;
-    test_parameters_.channels = 2;
+    test_parameters_.ch_layout.nb_channels = 2;
     test_parameters_.extradata = extradata_header_;
     test_parameters_.extradata_size = sizeof(extradata_header_);
   }
