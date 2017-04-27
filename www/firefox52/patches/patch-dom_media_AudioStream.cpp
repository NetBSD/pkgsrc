$NetBSD: patch-dom_media_AudioStream.cpp,v 1.1 2017/04/27 01:55:57 ryoon Exp $

--- dom/media/AudioStream.cpp.orig	2016-10-31 20:15:33.000000000 +0000
+++ dom/media/AudioStream.cpp
@@ -115,7 +115,9 @@ AudioStream::AudioStream(DataSource& aSo
   : mMonitor("AudioStream")
   , mChannels(0)
   , mOutChannels(0)
+#ifndef MOZ_SYSTEM_SOUNDTOUCH
   , mTimeStretcher(nullptr)
+#endif
   , mDumpFile(nullptr)
   , mState(INITIALIZED)
   , mDataSource(aSource)
@@ -130,9 +132,11 @@ AudioStream::~AudioStream()
   if (mDumpFile) {
     fclose(mDumpFile);
   }
+#ifndef MOZ_SYSTEM_SOUNDTOUCH
   if (mTimeStretcher) {
     soundtouch::destroySoundTouchObj(mTimeStretcher);
   }
+#endif
 }
 
 size_t
@@ -151,7 +155,11 @@ nsresult AudioStream::EnsureTimeStretche
 {
   mMonitor.AssertCurrentThreadOwns();
   if (!mTimeStretcher) {
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+    mTimeStretcher = new soundtouch::SoundTouch();
+#else
     mTimeStretcher = soundtouch::createSoundTouchObj();
+#endif
     mTimeStretcher->setSampleRate(mAudioClock.GetInputRate());
     mTimeStretcher->setChannels(mOutChannels);
     mTimeStretcher->setPitch(1.0);
