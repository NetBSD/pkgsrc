$NetBSD: patch-content_media_gstreamer_GStreamerLoader.cpp,v 1.1 2014/03/20 21:02:00 ryoon Exp $

--- content/media/gstreamer/GStreamerLoader.cpp.orig	2014-03-15 05:19:11.000000000 +0000
+++ content/media/gstreamer/GStreamerLoader.cpp
@@ -6,13 +6,21 @@
 #include <dlfcn.h>
 #include <stdio.h>
 
-#include "GStreamerLoader.h"
+#include "nsDebug.h"
 #include "mozilla/NullPtr.h"
 
+#include "GStreamerLoader.h"
+
 #define LIBGSTREAMER 0
 #define LIBGSTAPP 1
 #define LIBGSTVIDEO 2
 
+#ifdef __OpenBSD__
+#define LIB_GST_SUFFIX ".so"
+#else
+#define LIB_GST_SUFFIX ".so.0"
+#endif
+
 namespace mozilla {
 
 /*
@@ -32,6 +40,11 @@ namespace mozilla {
 GstBuffer * gst_buffer_ref_impl(GstBuffer *buf);
 void gst_buffer_unref_impl(GstBuffer *buf);
 void gst_message_unref_impl(GstMessage *msg);
+void gst_caps_unref_impl(GstCaps *caps);
+
+#if GST_VERSION_MAJOR == 1
+void gst_sample_unref_impl(GstSample *sample);
+#endif
 
 bool
 load_gstreamer()
@@ -58,32 +71,25 @@ load_gstreamer()
   if (major == GST_VERSION_MAJOR && minor == GST_VERSION_MINOR) {
     gstreamerLib = RTLD_DEFAULT;
   } else {
-#ifdef __OpenBSD__
-    gstreamerLib = dlopen("libgstreamer-0.10.so", RTLD_NOW | RTLD_LOCAL);
-#else
-    gstreamerLib = dlopen("libgstreamer-0.10.so.0", RTLD_NOW | RTLD_LOCAL);
-#endif
+    gstreamerLib = dlopen("libgstreamer-" GST_API_VERSION LIB_GST_SUFFIX, RTLD_NOW | RTLD_LOCAL);
   }
 
-  void *handles[] = {
+  void *handles[3] = {
     gstreamerLib,
-#ifdef __OpenBSD__
-    dlopen("libgstapp-0.10.so", RTLD_NOW | RTLD_LOCAL),
-    dlopen("libgstvideo-0.10.so", RTLD_NOW | RTLD_LOCAL)
-#else
-    dlopen("libgstapp-0.10.so.0", RTLD_NOW | RTLD_LOCAL),
-    dlopen("libgstvideo-0.10.so.0", RTLD_NOW | RTLD_LOCAL)
-#endif
+    dlopen("libgstapp-" GST_API_VERSION LIB_GST_SUFFIX, RTLD_NOW | RTLD_LOCAL),
+    dlopen("libgstvideo-" GST_API_VERSION LIB_GST_SUFFIX, RTLD_NOW | RTLD_LOCAL)
   };
 
   for (size_t i = 0; i < sizeof(handles) / sizeof(handles[0]); i++) {
     if (!handles[i]) {
+      NS_WARNING("Couldn't link gstreamer libraries");
       goto fail;
     }
   }
 
 #define GST_FUNC(lib, symbol) \
   if (!(symbol = (typeof(symbol))dlsym(handles[lib], #symbol))) { \
+    NS_WARNING("Couldn't link symbol " #symbol); \
     goto fail; \
   }
 #define REPLACE_FUNC(symbol) symbol = symbol##_impl;
@@ -123,4 +129,18 @@ gst_message_unref_impl(GstMessage *msg)
   gst_mini_object_unref(GST_MINI_OBJECT_CAST(msg));
 }
 
+#if GST_VERSION_MAJOR == 1
+void
+gst_sample_unref_impl(GstSample *sample)
+{
+  gst_mini_object_unref(GST_MINI_OBJECT_CAST(sample));
+}
+#endif
+
+void
+gst_caps_unref_impl(GstCaps *caps)
+{
+  gst_mini_object_unref(GST_MINI_OBJECT_CAST(caps));
+}
+
 }
