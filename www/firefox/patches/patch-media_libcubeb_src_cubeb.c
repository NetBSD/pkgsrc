$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.2 2016/03/08 21:32:52 ryoon Exp $

--- media/libcubeb/src/cubeb.c.orig	2016-02-25 23:01:58.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -60,6 +60,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 int
 validate_stream_params(cubeb_stream_params stream_params)
@@ -129,6 +132,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
