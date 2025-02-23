$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__video__decoder.cc,v 1.2 2025/02/23 18:59:28 markd Exp $

build with ffmpeg5 from archlinux
also ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_video_decoder.cc
@@ -86,7 +86,7 @@ bool FFmpegVideoDecoder::IsCodecSupporte
 }
 
 FFmpegVideoDecoder::FFmpegVideoDecoder(MediaLog* media_log)
-    : media_log_(media_log), state_(kUninitialized), decode_nalus_(false) {
+    : media_log_(media_log), state_(kUninitialized), decode_nalus_(false), timestamp_map_(128) {
   DVLOG(1) << __func__;
   thread_checker_.DetachFromThread();
 }
@@ -183,7 +183,6 @@ int FFmpegVideoDecoder::GetVideoBuffer(s
   frame->width = coded_size.width();
   frame->height = coded_size.height();
   frame->format = codec_context->pix_fmt;
-  frame->reordered_opaque = codec_context->reordered_opaque;
 
   // Now create an AVBufferRef for the data just allocated. It will own the
   // reference to the VideoFrame object.
@@ -318,8 +317,10 @@ bool FFmpegVideoDecoder::FFmpegDecode(co
     DCHECK(packet.data);
     DCHECK_GT(packet.size, 0);
 
-    // Let FFmpeg handle presentation timestamp reordering.
-    codec_context_->reordered_opaque = buffer.timestamp().InMicroseconds();
+    const int64_t timestamp = buffer.timestamp().InMicroseconds();
+    const TimestampId timestamp_id = timestamp_id_generator_.GenerateNextId();
+    timestamp_map_.Put(timestamp_id, timestamp);
+    packet.opaque = reinterpret_cast<void*>(timestamp_id.GetUnsafeValue());
   }
 
   switch (decoding_loop_->DecodePacket(
@@ -358,8 +359,13 @@ bool FFmpegVideoDecoder::OnNewFrame(AVFr
 
   scoped_refptr<VideoFrame> video_frame =
       reinterpret_cast<VideoFrame*>(av_buffer_get_opaque(frame->buf[0]));
+  const auto ts_id = TimestampId(reinterpret_cast<size_t>(frame->opaque));
+  const auto ts_lookup = timestamp_map_.Get(ts_id);
+  if (ts_lookup == timestamp_map_.end()) {
+    return false;
+  }
   video_frame->set_timestamp(
-      base::TimeDelta::FromMicroseconds(frame->reordered_opaque));
+      base::TimeDelta::FromMicroseconds(std::get<1>(*ts_lookup)));
   video_frame->metadata()->power_efficient = false;
   output_cb_.Run(video_frame);
   return true;
@@ -385,13 +391,15 @@ bool FFmpegVideoDecoder::ConfigureDecode
   codec_context_->thread_count = GetFFmpegVideoDecoderThreadCount(config);
   codec_context_->thread_type =
       FF_THREAD_SLICE | (low_delay ? 0 : FF_THREAD_FRAME);
+
   codec_context_->opaque = this;
   codec_context_->get_buffer2 = GetVideoBufferImpl;
+  codec_context_->flags |= AV_CODEC_FLAG_COPY_OPAQUE;
 
   if (decode_nalus_)
     codec_context_->flags2 |= AV_CODEC_FLAG2_CHUNKS;
 
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (!codec || avcodec_open2(codec_context_.get(), codec, NULL) < 0) {
     ReleaseFFmpegResources();
     return false;
