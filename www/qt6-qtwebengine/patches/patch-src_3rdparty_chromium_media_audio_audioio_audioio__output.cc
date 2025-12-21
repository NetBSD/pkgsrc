$NetBSD: patch-src_3rdparty_chromium_media_audio_audioio_audioio__output.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

use a unique name to not clash with audioio_input.cc

--- src/3rdparty/chromium/media/audio/audioio/audioio_output.cc.orig	2024-11-04 10:01:05.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audioio/audioio_output.cc
@@ -10,7 +10,7 @@
 
 namespace media {
 
-static const SampleFormat kSampleFormat = kSampleFormatS16;
+static const SampleFormat kSampleFormatAAO = kSampleFormatS16;
 
 void *AudioIOAudioOutputStream::ThreadEntry(void *arg) {
   AudioIOAudioOutputStream* self = static_cast<AudioIOAudioOutputStream*>(arg);
@@ -49,7 +49,7 @@ bool AudioIOAudioOutputStream::Open() {
   info.mode = AUMODE_PLAY;
   info.play.sample_rate = params.sample_rate();
   info.play.channels = params.channels();
-  info.play.precision = SampleFormatToBitsPerChannel(kSampleFormat);
+  info.play.precision = SampleFormatToBitsPerChannel(kSampleFormatAAO);
   info.play.encoding = AUDIO_ENCODING_SLINEAR_LE;
   info.play.pause = true;
 
@@ -69,7 +69,7 @@ bool AudioIOAudioOutputStream::Open() {
   state = kStopped;
   volpending = 0;
   vol = AUDIO_MAX_GAIN;
-  buffer = new char[audio_bus->frames() * params.GetBytesPerFrame(kSampleFormat)];
+  buffer = new char[audio_bus->frames() * params.GetBytesPerFrame(kSampleFormatAAO)];
   LOG(INFO) << "[AUDIOIO] OutputStream opened.";
   return true;
 
@@ -187,7 +187,7 @@ void AudioIOAudioOutputStream::Flush() {
 void AudioIOAudioOutputStream::ThreadLoop(void) {
   int avail, count, ret, frames, move;
   int written_bytes = 0;
-  int framesize = params.GetBytesPerFrame(kSampleFormat);
+  int framesize = params.GetBytesPerFrame(kSampleFormatAAO);
   int hw_delay = 0;
   struct audio_info info;
   struct audio_offset offset;
@@ -249,4 +249,4 @@ void AudioIOAudioOutputStream::ThreadLoo
   LOG(INFO) << "[AUDIOIO] Output:ThreadLoop() stopped.";
 }
 
-}  // namespace media
\ No newline at end of file
+}  // namespace media
