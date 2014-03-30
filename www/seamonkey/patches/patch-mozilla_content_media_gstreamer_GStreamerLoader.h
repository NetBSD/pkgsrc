$NetBSD: patch-mozilla_content_media_gstreamer_GStreamerLoader.h,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/content/media/gstreamer/GStreamerLoader.h.orig	2014-03-19 01:41:47.000000000 +0000
+++ mozilla/content/media/gstreamer/GStreamerLoader.h
@@ -22,6 +22,11 @@
 #include <gst/video/video.h>
 #pragma GCC diagnostic pop
 
+#if GST_VERSION_MAJOR == 1
+#include <gst/video/gstvideometa.h>
+#include <gst/video/gstvideopool.h>
+#endif
+
 namespace mozilla {
 
 /*
@@ -42,4 +47,7 @@ bool load_gstreamer();
 
 }
 
+#undef GST_CAPS_ANY
+#define GST_CAPS_ANY (*_gst_caps_any)
+
 #endif // GStreamerLoader_h_
