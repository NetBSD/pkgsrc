$NetBSD: patch-src_3rdparty_chromium_media_cdm_library__cdm_clear__key__cdm_ffmpeg__cdm__audio__decoder.cc,v 1.1 2025/02/23 18:59:28 markd Exp $

support ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/cdm/library_cdm/clear_key_cdm/ffmpeg_cdm_audio_decoder.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/cdm/library_cdm/clear_key_cdm/ffmpeg_cdm_audio_decoder.cc
@@ -73,7 +73,7 @@ void CdmAudioDecoderConfigToAVCodecConte
       codec_context->sample_fmt = AV_SAMPLE_FMT_NONE;
   }
 
-  codec_context->channels = config.channel_count;
+  codec_context->ch_layout.nb_channels = config.channel_count;
   codec_context->sample_rate = config.samples_per_second;
 
   if (config.extra_data) {
@@ -123,8 +123,8 @@ void CopySamples(cdm::AudioFormat cdm_fo
     case cdm::kAudioFormatPlanarS16:
     case cdm::kAudioFormatPlanarF32: {
       const int decoded_size_per_channel =
-          decoded_audio_size / av_frame.channels;
-      for (int i = 0; i < av_frame.channels; ++i) {
+          decoded_audio_size / av_frame.ch_layout.nb_channels;
+      for (int i = 0; i < av_frame.ch_layout.nb_channels; ++i) {
         memcpy(output_buffer, av_frame.extended_data[i],
                decoded_size_per_channel);
         output_buffer += decoded_size_per_channel;
@@ -184,13 +184,14 @@ bool FFmpegCdmAudioDecoder::Initialize(
   // Success!
   decoding_loop_.reset(new FFmpegDecodingLoop(codec_context_.get()));
   samples_per_second_ = config.samples_per_second;
-  bytes_per_frame_ = codec_context_->channels * config.bits_per_channel / 8;
+  bytes_per_frame_ =
+      codec_context_->ch_layout.nb_channels * config.bits_per_channel / 8;
   output_timestamp_helper_.reset(
       new AudioTimestampHelper(config.samples_per_second));
   is_initialized_ = true;
 
   // Store initial values to guard against midstream configuration changes.
-  channels_ = codec_context_->channels;
+  channels_ = codec_context_->ch_layout.nb_channels;
   av_sample_format_ = codec_context_->sample_fmt;
 
   return true;
@@ -290,17 +291,18 @@ cdm::Status FFmpegCdmAudioDecoder::Decod
   for (auto& frame : audio_frames) {
     int decoded_audio_size = 0;
     if (frame->sample_rate != samples_per_second_ ||
-        frame->channels != channels_ || frame->format != av_sample_format_) {
+        frame->ch_layout.nb_channels != channels_ ||
+        frame->format != av_sample_format_) {
       DLOG(ERROR) << "Unsupported midstream configuration change!"
                   << " Sample Rate: " << frame->sample_rate << " vs "
-                  << samples_per_second_ << ", Channels: " << frame->channels
+                  << samples_per_second_ << ", Channels: " << frame->ch_layout.nb_channels
                   << " vs " << channels_ << ", Sample Format: " << frame->format
                   << " vs " << av_sample_format_;
       return cdm::kDecodeError;
     }
 
     decoded_audio_size = av_samples_get_buffer_size(
-        nullptr, codec_context_->channels, frame->nb_samples,
+        nullptr, codec_context_->ch_layout.nb_channels, frame->nb_samples,
         codec_context_->sample_fmt, 1);
     if (!decoded_audio_size)
       continue;
@@ -319,7 +321,7 @@ bool FFmpegCdmAudioDecoder::OnNewFrame(
     size_t* total_size,
     std::vector<std::unique_ptr<AVFrame, ScopedPtrAVFreeFrame>>* audio_frames,
     AVFrame* frame) {
-  *total_size += av_samples_get_buffer_size(nullptr, codec_context_->channels,
+  *total_size += av_samples_get_buffer_size(nullptr, codec_context_->ch_layout.nb_channels,
                                             frame->nb_samples,
                                             codec_context_->sample_fmt, 1);
   audio_frames->emplace_back(av_frame_clone(frame));
