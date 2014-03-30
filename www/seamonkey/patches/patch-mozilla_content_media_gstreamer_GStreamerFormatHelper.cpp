$NetBSD: patch-mozilla_content_media_gstreamer_GStreamerFormatHelper.cpp,v 1.3 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/content/media/gstreamer/GStreamerFormatHelper.cpp.orig	2014-03-19 01:41:47.000000000 +0000
+++ mozilla/content/media/gstreamer/GStreamerFormatHelper.cpp
@@ -294,12 +294,23 @@ bool GStreamerFormatHelper::CanHandleCod
 GList* GStreamerFormatHelper::GetFactories() {
   NS_ASSERTION(sLoadOK, "GStreamer library not linked");
 
-  uint32_t cookie = gst_default_registry_get_feature_list_cookie ();
+#if GST_VERSION_MAJOR >= 1
+  uint32_t cookie = gst_registry_get_feature_list_cookie(gst_registry_get());
+#else
+  uint32_t cookie = gst_default_registry_get_feature_list_cookie();
+#endif
   if (cookie != mCookie) {
     g_list_free(mFactories);
+#if GST_VERSION_MAJOR >= 1
+    mFactories =
+      gst_registry_feature_filter(gst_registry_get(),
+                                  (GstPluginFeatureFilter)FactoryFilter,
+                                  false, nullptr);
+#else
     mFactories =
       gst_default_registry_feature_filter((GstPluginFeatureFilter)FactoryFilter,
                                           false, nullptr);
+#endif
     mCookie = cookie;
   }
 
