$NetBSD: patch-dom_media_AudioStream.cpp,v 1.2 2017/09/30 05:34:12 ryoon Exp $

--- dom/media/AudioStream.cpp.orig	2017-09-14 20:15:56.000000000 +0000
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
@@ -135,9 +137,11 @@ AudioStream::~AudioStream()
   if (mDumpFile) {
     fclose(mDumpFile);
   }
+#ifndef MOZ_SYSTEM_SOUNDTOUCH
   if (mTimeStretcher) {
     soundtouch::destroySoundTouchObj(mTimeStretcher);
   }
+#endif
 #if defined(XP_WIN)
   if (XRE_IsContentProcess()) {
     audio::AudioNotificationReceiver::Unregister(this);
@@ -161,7 +165,11 @@ nsresult AudioStream::EnsureTimeStretche
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
