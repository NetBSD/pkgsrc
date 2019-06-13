$NetBSD: patch-mozilla_media_libcubeb_src_cubeb.c,v 1.4 2019/06/13 10:53:11 nia Exp $

--- mozilla/media/libcubeb/src/cubeb.c.orig	2018-07-12 02:17:30.000000000 +0000
+++ mozilla/media/libcubeb/src/cubeb.c
@@ -45,6 +45,9 @@ int wasapi_init(cubeb ** context, char c
 #if defined(USE_SNDIO)
 int sndio_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_SUN)
+int sun_init(cubeb ** context, char const * context_name);
+#endif
 #if defined(USE_OPENSL)
 int opensl_init(cubeb ** context, char const * context_name);
 #endif
@@ -54,6 +57,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 
 static int
@@ -132,6 +138,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
@@ -141,6 +150,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
