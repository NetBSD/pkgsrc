$NetBSD: patch-dom_media_AudioStream.h,v 1.4 2017/09/30 05:34:12 ryoon Exp $

--- dom/media/AudioStream.h.orig	2017-09-14 20:15:56.000000000 +0000
+++ dom/media/AudioStream.h
@@ -16,7 +16,11 @@
 #include "mozilla/TimeStamp.h"
 #include "mozilla/UniquePtr.h"
 #include "CubebUtils.h"
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+#include "soundtouch/SoundTouch.h"
+#else
 #include "soundtouch/SoundTouchFactory.h"
+#endif
 
 #if defined(XP_WIN)
 #include "mozilla/audio/AudioNotificationReceiver.h"
@@ -299,7 +303,11 @@ private:
   uint32_t mChannels;
   uint32_t mOutChannels;
   AudioClock mAudioClock;
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+  nsAutoPtr<soundtouch::SoundTouch> mTimeStretcher;
+#else
   soundtouch::SoundTouch* mTimeStretcher;
+#endif
 
   // Output file for dumping audio
   FILE* mDumpFile;
