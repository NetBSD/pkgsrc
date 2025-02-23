$NetBSD: patch-src_3rdparty_chromium_media_ffmpeg_ffmpeg__common.cc,v 1.1 2025/02/23 18:59:28 markd Exp $

fix for ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/ffmpeg/ffmpeg_common.cc
@@ -341,10 +341,11 @@ bool AVCodecContextToAudioDecoderConfig(
       codec_context->sample_fmt, codec_context->codec_id);
 
   ChannelLayout channel_layout =
-      codec_context->channels > 8
+      codec_context->ch_layout.nb_channels > 8
           ? CHANNEL_LAYOUT_DISCRETE
-          : ChannelLayoutToChromeChannelLayout(codec_context->channel_layout,
-                                               codec_context->channels);
+          : ChannelLayoutToChromeChannelLayout(
+                codec_context->ch_layout.u.mask,
+                codec_context->ch_layout.nb_channels);
 
   int sample_rate = codec_context->sample_rate;
   switch (codec) {
@@ -397,7 +398,7 @@ bool AVCodecContextToAudioDecoderConfig(
                      extra_data, encryption_scheme, seek_preroll,
                      codec_context->delay);
   if (channel_layout == CHANNEL_LAYOUT_DISCRETE)
-    config->SetChannelsForDiscrete(codec_context->channels);
+    config->SetChannelsForDiscrete(codec_context->ch_layout.nb_channels);
 
 #if BUILDFLAG(ENABLE_PLATFORM_AC3_EAC3_AUDIO)
   // These are bitstream formats unknown to ffmpeg, so they don't have
@@ -413,7 +414,9 @@ bool AVCodecContextToAudioDecoderConfig(
 #if BUILDFLAG(USE_PROPRIETARY_CODECS)
   // TODO(dalecurtis): Just use the profile from the codec context if ffmpeg
   // ever starts supporting xHE-AAC.
-  if (codec == kCodecAAC && codec_context->profile == FF_PROFILE_UNKNOWN) {
+  constexpr uint8_t kXHEAAc = 41;
+  if (codec == kCodecAAC && codec_context->profile == FF_PROFILE_UNKNOWN ||
+      codec_context->profile == kXHEAAc) {
     // Errors aren't fatal here, so just drop any MediaLog messages.
     NullMediaLog media_log;
     mp4::AAC aac_parser;
@@ -462,7 +465,7 @@ void AudioDecoderConfigToAVCodecContext(
 
   // TODO(scherkus): should we set |channel_layout|? I'm not sure if FFmpeg uses
   // said information to decode.
-  codec_context->channels = config.channels();
+  codec_context->ch_layout.nb_channels = config.channels();
   codec_context->sample_rate = config.samples_per_second();
 
   if (config.extra_data().empty()) {
