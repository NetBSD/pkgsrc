$NetBSD: patch-Source_WebCore_platform_audio_gstreamer_AudioFileReaderGStreamer.cpp,v 1.1 2022/04/22 06:06:38 markd Exp $

Fix build issue with latest gstreamer
error: braces around scalar initializer

--- Source/WebCore/platform/audio/gstreamer/AudioFileReaderGStreamer.cpp.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/WebCore/platform/audio/gstreamer/AudioFileReaderGStreamer.cpp
@@ -230,7 +230,7 @@ void AudioFileReader::handleNewDeinterle
         [](GstAppSink* sink, gpointer userData) -> GstFlowReturn {
             return static_cast<AudioFileReader*>(userData)->handleSample(sink);
         },
-        { nullptr }
+        nullptr
     };
     gst_app_sink_set_callbacks(GST_APP_SINK(sink), &callbacks, this, 0);
 
