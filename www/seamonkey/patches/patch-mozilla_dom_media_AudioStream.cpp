$NetBSD: patch-mozilla_dom_media_AudioStream.cpp,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/dom/media/AudioStream.cpp.orig	2017-07-07 05:36:08.000000000 +0000
+++ mozilla/dom/media/AudioStream.cpp
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
