$NetBSD: patch-mozilla_content_media_AudioStream.cpp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/content/media/AudioStream.cpp.orig	2013-05-03 03:07:50.000000000 +0000
+++ mozilla/content/media/AudioStream.cpp
@@ -314,7 +314,7 @@ nsresult NativeAudioStream::Init(int32_t
   mChannels = aNumChannels;
 
   if (sa_stream_create_pcm(reinterpret_cast<sa_stream_t**>(&mAudioHandle),
-                           NULL,
+                           "Mozilla",
                            SA_MODE_WRONLY,
                            SA_PCM_FORMAT_S16_NE,
                            aRate,
