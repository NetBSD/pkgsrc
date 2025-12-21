$NetBSD: patch-src_3rdparty_chromium_media_audio_audioio_audioio__input.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

use a unique name to not clash with audioio_output.cc

--- src/3rdparty/chromium/media/audio/audioio/audioio_input.cc.orig	2024-11-04 10:01:05.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audioio/audioio_input.cc
@@ -9,7 +9,7 @@
 
 namespace media {
 
-static const SampleFormat kSampleFormat = kSampleFormatS16;
+static const SampleFormat kSampleFormatAAI = kSampleFormatS16;
 
 void *AudioIOAudioInputStream::ThreadEntry(void *arg) {
   AudioIOAudioInputStream* self = static_cast<AudioIOAudioInputStream*>(arg);
@@ -52,7 +52,7 @@ AudioInputStream::OpenOutcome AudioIOAud
   info.mode = AUMODE_RECORD;
   info.record.sample_rate = params.sample_rate();
   info.record.channels = params.channels();
-  info.record.precision = SampleFormatToBitsPerChannel(kSampleFormat);
+  info.record.precision = SampleFormatToBitsPerChannel(kSampleFormatAAI);
   info.record.encoding = AUDIO_ENCODING_SLINEAR_LE;
   info.record.pause = true;
 
@@ -72,7 +72,7 @@ AudioInputStream::OpenOutcome AudioIOAud
   state = kStopped;
   inputvol = 1.0;
   vol = AUDIO_MAX_GAIN;
-  buffer = new char[audio_bus->frames() * params.GetBytesPerFrame(kSampleFormat)];
+  buffer = new char[audio_bus->frames() * params.GetBytesPerFrame(kSampleFormatAAI)];
   LOG(INFO) << "[AUDIOIO] InputStream opened.";
   return OpenOutcome::kSuccess;
 error:
@@ -206,7 +206,7 @@ void AudioIOAudioInputStream::SetOutputD
 
 void AudioIOAudioInputStream::ThreadLoop(void) {
   size_t bytes, n, frames, nframes, move, count;
-  size_t framesize = params.GetBytesPerFrame(kSampleFormat);
+  size_t framesize = params.GetBytesPerFrame(kSampleFormatAAI);
   size_t read_bytes = 0;
   size_t hw_delay = 0;
   double normalized_volume = 0.0;
