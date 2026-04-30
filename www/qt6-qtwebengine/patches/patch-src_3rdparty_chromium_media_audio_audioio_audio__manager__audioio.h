$NetBSD: patch-src_3rdparty_chromium_media_audio_audioio_audio__manager__audioio.h,v 1.1 2026/04/30 06:39:41 adam Exp $

Match the definition used everywhere else

--- src/3rdparty/chromium/media/audio/audioio/audio_manager_audioio.h.orig	2024-11-04 10:01:05.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audioio/audio_manager_audioio.h
@@ -39,7 +39,7 @@ class MEDIA_EXPORT AudioManagerAudioIO :
   // version of this interface.
   AudioParameters GetInputStreamParameters(const std::string& device_id) override;
   // Gets the name of the audio manager (e.g., Windows, Mac, PulseAudio).
-  const char* GetName() override;
+  const std::string_view GetName() override;
 
   // Implementation of AudioManagerBase.
   // Creates the output stream for the |AUDIO_PCM_LINEAR| format. The legacy
@@ -84,4 +84,4 @@ class MEDIA_EXPORT AudioManagerAudioIO :
 
 }  // namespace media
 
-#endif  // MEDIA_AUDIO_AUDIOIO_AUDIO_MANAGER_AUDIOIO_H_
\ No newline at end of file
+#endif  // MEDIA_AUDIO_AUDIOIO_AUDIO_MANAGER_AUDIOIO_H_
