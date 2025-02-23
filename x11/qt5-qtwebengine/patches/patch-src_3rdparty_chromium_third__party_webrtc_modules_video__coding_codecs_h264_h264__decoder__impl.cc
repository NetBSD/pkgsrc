$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_video__coding_codecs_h264_h264__decoder__impl.cc,v 1.2 2025/02/23 18:59:28 markd Exp $

build with ffmpeg5 from archlinux
and ffmpeg7 from ArchLinux

--- src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -114,7 +114,6 @@ int H264DecoderImpl::AVGetBuffer2(AVCode
   int total_size = y_size + 2 * uv_size;
 
   av_frame->format = context->pix_fmt;
-  av_frame->reordered_opaque = context->reordered_opaque;
 
   // Set |av_frame| members as required by FFmpeg.
   av_frame->data[kYPlaneIndex] = frame_buffer->MutableDataY();
@@ -203,7 +202,7 @@ int32_t H264DecoderImpl::InitDecode(cons
   // a pointer |this|.
   av_context_->opaque = this;
 
-  AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(av_context_->codec_id);
   if (!codec) {
     // This is an indication that FFmpeg has not been initialized or it has not
     // been compiled/initialized with the correct set of codecs.
@@ -273,8 +272,6 @@ int32_t H264DecoderImpl::Decode(const En
     return WEBRTC_VIDEO_CODEC_ERROR;
   }
   packet.size = static_cast<int>(input_image.size());
-  int64_t frame_timestamp_us = input_image.ntp_time_ms_ * 1000;  // ms -> μs
-  av_context_->reordered_opaque = frame_timestamp_us;
 
   int result = avcodec_send_packet(av_context_.get(), &packet);
   if (result < 0) {
@@ -290,10 +287,6 @@ int32_t H264DecoderImpl::Decode(const En
     return WEBRTC_VIDEO_CODEC_ERROR;
   }
 
-  // We don't expect reordering. Decoded frame tamestamp should match
-  // the input one.
-  RTC_DCHECK_EQ(av_frame_->reordered_opaque, frame_timestamp_us);
-
   absl::optional<uint8_t> qp;
   // TODO(sakal): Maybe it is possible to get QP directly from FFmpeg.
   h264_bitstream_parser_.ParseBitstream(input_image.data(), input_image.size());
