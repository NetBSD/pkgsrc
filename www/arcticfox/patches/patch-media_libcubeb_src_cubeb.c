$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.1 2022/02/05 20:51:07 nia Exp $

- Add Sun Audio support.

--- media/libcubeb/src/cubeb.c.orig	2021-12-03 05:22:04.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -50,6 +50,9 @@ int wasapi_init(cubeb ** context, char c
 #if defined(USE_SNDIO)
 int sndio_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_SUN)
+int sun_init(cubeb ** context, char const * context_name);
+#endif
 #if defined(USE_OPENSL)
 int opensl_init(cubeb ** context, char const * context_name);
 #endif
@@ -116,6 +119,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
