$NetBSD: patch-Source_WebCore_platform_graphics_gstreamer_ImageDecoderGStreamer.cpp,v 1.1 2024/06/23 13:59:41 mef Exp $

error: braces around scalar initializer for type 'gboolean (*)(GstAppSink*, GstQuery*, gpointer)' {aka 'int (*)(_GstAppSink*, _GstQuery*, void*)'}
     };
     ^

--- Source/WebCore/platform/graphics/gstreamer/ImageDecoderGStreamer.cpp.orig	2023-02-14 18:01:07.365508600 +0900
+++ Source/WebCore/platform/graphics/gstreamer/ImageDecoderGStreamer.cpp	2024-06-23 21:02:18.568537756 +0900
@@ -274,7 +274,7 @@ void ImageDecoderGStreamer::InnerDecoder
         // new_event
         nullptr,
 #endif
-        { nullptr }
+        nullptr
     };
     gst_app_sink_set_callbacks(GST_APP_SINK(sink), &callbacks, &m_decoder, nullptr);
 
