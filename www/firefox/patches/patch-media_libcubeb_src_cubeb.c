$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.9 2018/11/04 04:46:57 ryoon Exp $

* Support OSS audio

--- media/libcubeb/src/cubeb.c.orig	2018-10-18 20:06:09.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -60,6 +60,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 static int
 validate_stream_params(cubeb_stream_params * input_stream_params,
@@ -160,6 +163,10 @@ cubeb_init(cubeb ** context, char const 
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
@@ -204,6 +211,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
