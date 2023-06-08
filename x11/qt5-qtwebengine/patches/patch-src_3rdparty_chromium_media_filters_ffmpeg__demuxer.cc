$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__demuxer.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 - from archlinux

--- src/3rdparty/chromium/media/filters/ffmpeg_demuxer.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_demuxer.cc
@@ -98,12 +98,12 @@ static base::TimeDelta ExtractStartTime(
 
   // Next try to use the first DTS value, for codecs where we know PTS == DTS
   // (excludes all H26x codecs). The start time must be returned in PTS.
-  if (stream->first_dts != kNoFFmpegTimestamp &&
+  if (av_stream_get_first_dts(stream) != kNoFFmpegTimestamp &&
       stream->codecpar->codec_id != AV_CODEC_ID_HEVC &&
       stream->codecpar->codec_id != AV_CODEC_ID_H264 &&
       stream->codecpar->codec_id != AV_CODEC_ID_MPEG4) {
     const base::TimeDelta first_pts =
-        ConvertFromTimeBase(stream->time_base, stream->first_dts);
+        ConvertFromTimeBase(stream->time_base, av_stream_get_first_dts(stream));
     if (first_pts < start_time)
       start_time = first_pts;
   }
@@ -408,11 +408,11 @@ void FFmpegDemuxerStream::EnqueuePacket(
   scoped_refptr<DecoderBuffer> buffer;
 
   if (type() == DemuxerStream::TEXT) {
-    int id_size = 0;
+    size_t id_size = 0;
     uint8_t* id_data = av_packet_get_side_data(
         packet.get(), AV_PKT_DATA_WEBVTT_IDENTIFIER, &id_size);
 
-    int settings_size = 0;
+    size_t settings_size = 0;
     uint8_t* settings_data = av_packet_get_side_data(
         packet.get(), AV_PKT_DATA_WEBVTT_SETTINGS, &settings_size);
 
@@ -424,7 +424,7 @@ void FFmpegDemuxerStream::EnqueuePacket(
     buffer = DecoderBuffer::CopyFrom(packet->data, packet->size,
                                      side_data.data(), side_data.size());
   } else {
-    int side_data_size = 0;
+    size_t side_data_size = 0;
     uint8_t* side_data = av_packet_get_side_data(
         packet.get(), AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL, &side_data_size);
 
@@ -485,7 +485,7 @@ void FFmpegDemuxerStream::EnqueuePacket(
                                        packet->size - data_offset);
     }
 
-    int skip_samples_size = 0;
+    size_t skip_samples_size = 0;
     const uint32_t* skip_samples_ptr =
         reinterpret_cast<const uint32_t*>(av_packet_get_side_data(
             packet.get(), AV_PKT_DATA_SKIP_SAMPLES, &skip_samples_size));
