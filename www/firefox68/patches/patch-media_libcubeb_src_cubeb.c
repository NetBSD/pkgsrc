$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.1.6.1 2020/03/13 20:02:45 bsiegert Exp $

* Support Sun audio

--- media/libcubeb/src/cubeb.c.orig	2020-03-05 20:57:11.000000000 +0000
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
@@ -195,6 +198,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
