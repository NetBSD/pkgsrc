$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.10 2019/06/13 22:05:24 nia Exp $

* Support OSS audio
* Support Sun audio

--- media/libcubeb/src/cubeb.c.orig	2019-06-09 08:15:58.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -51,6 +51,9 @@ int wasapi_init(cubeb ** context, char c
 #if defined(USE_SNDIO)
 int sndio_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_SUN)
+int sun_init(cubeb ** context, char const * context_name);
+#endif
 #if defined(USE_OPENSL)
 int opensl_init(cubeb ** context, char const * context_name);
 #endif
@@ -60,6 +63,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 static int
 validate_stream_params(cubeb_stream_params * input_stream_params,
@@ -160,6 +166,10 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
       init_oneshot = kai_init;
 #endif
+    } else if (!strcmp(backend_name, "oss")) {
+#if defined(USE_OSS)
+      init_oneshot = oss_init;
+#endif
     } else {
       /* Already set */
     }
@@ -195,6 +205,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
@@ -204,6 +217,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
