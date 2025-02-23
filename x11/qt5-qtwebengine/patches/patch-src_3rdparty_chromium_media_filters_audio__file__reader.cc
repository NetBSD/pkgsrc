$NetBSD: patch-src_3rdparty_chromium_media_filters_audio__file__reader.cc,v 1.2 2025/02/23 18:59:28 markd Exp $

build with ffmpeg5 - from archlinux
also ffmeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/audio_file_reader.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/audio_file_reader.cc
@@ -85,7 +85,7 @@ bool AudioFileReader::OpenDemuxer() {
 }
 
 bool AudioFileReader::OpenDecoder() {
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (codec) {
     // MP3 decodes to S16P which we don't support, tell it to use S16 instead.
     if (codec_context_->sample_fmt == AV_SAMPLE_FMT_S16P)
@@ -112,14 +112,15 @@ bool AudioFileReader::OpenDecoder() {
 
   // Verify the channel layout is supported by Chrome.  Acts as a sanity check
   // against invalid files.  See http://crbug.com/171962
-  if (ChannelLayoutToChromeChannelLayout(codec_context_->channel_layout,
-                                         codec_context_->channels) ==
+  if (ChannelLayoutToChromeChannelLayout(
+          codec_context_->ch_layout.u.mask,
+          codec_context_->ch_layout.nb_channels) ==
       CHANNEL_LAYOUT_UNSUPPORTED) {
     return false;
   }
 
   // Store initial values to guard against midstream configuration changes.
-  channels_ = codec_context_->channels;
+  channels_ = codec_context_->ch_layout.nb_channels;
   audio_codec_ = CodecIDToAudioCodec(codec_context_->codec_id);
   sample_rate_ = codec_context_->sample_rate;
   av_sample_format_ = codec_context_->sample_fmt;
@@ -222,7 +223,7 @@ bool AudioFileReader::OnNewFrame(
   if (frames_read < 0)
     return false;
 
-  const int channels = frame->channels;
+  const int channels = frame->ch_layout.nb_channels;
   if (frame->sample_rate != sample_rate_ || channels != channels_ ||
       frame->format != av_sample_format_) {
     DLOG(ERROR) << "Unsupported midstream configuration change!"
@@ -241,10 +242,10 @@ bool AudioFileReader::OnNewFrame(
   // silence from being output. In the case where we are also discarding some
   // portion of the packet (as indicated by a negative pts), we further want to
   // adjust the duration downward by however much exists before zero.
-  if (audio_codec_ == kCodecAAC && frame->pkt_duration) {
+  if (audio_codec_ == kCodecAAC && frame->duration) {
     const base::TimeDelta pkt_duration = ConvertFromTimeBase(
         glue_->format_context()->streams[stream_index_]->time_base,
-        frame->pkt_duration + std::min(static_cast<int64_t>(0), frame->pts));
+        frame->duration + std::min(static_cast<int64_t>(0), frame->pts));
     const base::TimeDelta frame_duration = base::TimeDelta::FromSecondsD(
         frames_read / static_cast<double>(sample_rate_));
 
