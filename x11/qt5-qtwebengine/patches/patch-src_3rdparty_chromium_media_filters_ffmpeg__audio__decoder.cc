$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__audio__decoder.cc,v 1.2 2025/02/23 18:59:28 markd Exp $

build with ffmpeg5 - from archlinux
and with ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/filters/ffmpeg_audio_decoder.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_audio_decoder.cc
@@ -27,7 +27,7 @@ namespace media {
 
 // Return the number of channels from the data in |frame|.
 static inline int DetermineChannels(AVFrame* frame) {
-  return frame->channels;
+  return frame->ch_layout.nb_channels;
 }
 
 // Called by FFmpeg's allocation routine to allocate a buffer. Uses
@@ -227,7 +227,7 @@ bool FFmpegAudioDecoder::OnNewFrame(cons
   // Translate unsupported into discrete layouts for discrete configurations;
   // ffmpeg does not have a labeled discrete configuration internally.
   ChannelLayout channel_layout = ChannelLayoutToChromeChannelLayout(
-      codec_context_->channel_layout, codec_context_->channels);
+      codec_context_->ch_layout.u.mask, codec_context_->ch_layout.nb_channels);
   if (channel_layout == CHANNEL_LAYOUT_UNSUPPORTED &&
       config_.channel_layout() == CHANNEL_LAYOUT_DISCRETE) {
     channel_layout = CHANNEL_LAYOUT_DISCRETE;
@@ -329,7 +329,7 @@ bool FFmpegAudioDecoder::ConfigureDecode
     }
   }
 
-  AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
+  const AVCodec* codec = avcodec_find_decoder(codec_context_->codec_id);
   if (!codec ||
       avcodec_open2(codec_context_.get(), codec, &codec_options) < 0) {
     DLOG(ERROR) << "Could not initialize audio decoder: "
@@ -344,11 +344,11 @@ bool FFmpegAudioDecoder::ConfigureDecode
   // Success!
   av_sample_format_ = codec_context_->sample_fmt;
 
-  if (codec_context_->channels != config.channels()) {
+  if (codec_context_->ch_layout.nb_channels != config.channels()) {
     MEDIA_LOG(ERROR, media_log_)
         << "Audio configuration specified " << config.channels()
         << " channels, but FFmpeg thinks the file contains "
-        << codec_context_->channels << " channels";
+        << codec_context_->ch_layout.nb_channels << " channels";
     ReleaseFFmpegResources();
     state_ = kUninitialized;
     return false;
@@ -398,7 +398,7 @@ int FFmpegAudioDecoder::GetAudioBuffer(s
   if (frame->nb_samples <= 0)
     return AVERROR(EINVAL);
 
-  if (s->channels != channels) {
+  if (s->ch_layout.nb_channels != channels) {
     DLOG(ERROR) << "AVCodecContext and AVFrame disagree on channel count.";
     return AVERROR(EINVAL);
   }
@@ -431,7 +431,8 @@ int FFmpegAudioDecoder::GetAudioBuffer(s
   ChannelLayout channel_layout =
       config_.channel_layout() == CHANNEL_LAYOUT_DISCRETE
           ? CHANNEL_LAYOUT_DISCRETE
-          : ChannelLayoutToChromeChannelLayout(s->channel_layout, s->channels);
+          : ChannelLayoutToChromeChannelLayout(s->ch_layout.u.mask,
+                                               s->ch_layout.nb_channels);
 
   if (channel_layout == CHANNEL_LAYOUT_UNSUPPORTED) {
     DLOG(ERROR) << "Unsupported channel layout.";
