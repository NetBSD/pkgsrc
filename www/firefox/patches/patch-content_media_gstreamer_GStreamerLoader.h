$NetBSD: patch-content_media_gstreamer_GStreamerLoader.h,v 1.1 2014/03/20 21:02:00 ryoon Exp $

--- content/media/gstreamer/GStreamerLoader.h.orig	2014-03-15 05:19:11.000000000 +0000
+++ content/media/gstreamer/GStreamerLoader.h
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
