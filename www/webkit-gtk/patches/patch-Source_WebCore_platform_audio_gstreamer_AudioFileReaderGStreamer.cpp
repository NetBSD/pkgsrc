$NetBSD: patch-Source_WebCore_platform_audio_gstreamer_AudioFileReaderGStreamer.cpp,v 1.1 2024/06/23 13:59:41 mef Exp $

 error: braces around scalar initializer for type  gboolean (*)(GstAppSink*, GstQuery*, gpointer)' {aka 'int (*)(_GstAppSink*, _GstQuery*, void*)'}
     };
     ^
--- Source/WebCore/platform/audio/gstreamer/AudioFileReaderGStreamer.cpp.orig	2023-02-14 18:01:07.357508400 +0900
+++ Source/WebCore/platform/audio/gstreamer/AudioFileReaderGStreamer.cpp	2024-06-23 21:17:02.539869040 +0900
@@ -287,7 +287,7 @@ void AudioFileReader::handleNewDeinterle
         // new_event
         nullptr,
 #endif
-        { nullptr }
+        nullptr
     };
     gst_app_sink_set_callbacks(GST_APP_SINK(sink), &callbacks, this, nullptr);
 
