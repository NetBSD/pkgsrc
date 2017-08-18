$NetBSD: patch-mozilla_dom_media_AudioStream.h,v 1.3 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/dom/media/AudioStream.h.orig	2017-07-07 05:36:09.000000000 +0000
+++ mozilla/dom/media/AudioStream.h
@@ -16,7 +16,11 @@
 #include "mozilla/TimeStamp.h"
 #include "mozilla/UniquePtr.h"
 #include "CubebUtils.h"
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+#include "soundtouch/SoundTouch.h"
+#else
 #include "soundtouch/SoundTouchFactory.h"
+#endif
 
 namespace mozilla {
 
@@ -281,7 +285,11 @@ private:
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
