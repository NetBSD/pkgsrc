$NetBSD: patch-Source_WebCore_platform_audio_gstreamer_AudioSourceProviderGStreamer.cpp,v 1.1 2024/06/23 13:59:41 mef Exp $

 error: braces around scalar initializer for type 'gboolean (*)(GstAppSink*, GstQuery*, gpointer)' {aka 'int (*)(_GstAppSink*, _GstQuery*, void*)'}
     };

--- Source/WebCore/platform/audio/gstreamer/AudioSourceProviderGStreamer.cpp.orig	2024-06-23 20:38:51.854577969 +0900
+++ Source/WebCore/platform/audio/gstreamer/AudioSourceProviderGStreamer.cpp	2024-06-23 20:39:25.862340965 +0900
@@ -363,7 +363,7 @@ void AudioSourceProviderGStreamer::handl
         // new_event
         nullptr,
 #endif
-        { nullptr }
+        nullptr
     };
     gst_app_sink_set_callbacks(GST_APP_SINK(sink), &callbacks, this, nullptr);
     // The provider client might request samples faster than the current clock speed, so this sink
