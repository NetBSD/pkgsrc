$NetBSD: patch-mozilla_media_libcubeb_src_cubeb.c,v 1.6 2020/05/07 19:36:53 nia Exp $

- Sun Audio support.

--- mozilla/media/libcubeb/src/cubeb.c.orig	2020-02-17 23:37:58.000000000 +0000
+++ mozilla/media/libcubeb/src/cubeb.c
@@ -46,6 +46,9 @@ int wasapi_init(cubeb ** context, char c
 #if defined(USE_SNDIO)
 int sndio_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_SUN)
+int sun_init(cubeb ** context, char const * context_name);
+#endif
 #if defined(USE_OPENSL)
 int opensl_init(cubeb ** context, char const * context_name);
 #endif
@@ -143,6 +146,10 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
       init_oneshot = sndio_init;
 #endif
+    } else if (!strcmp(backend_name, "sun")) {
+#if defined(USE_SUN)
+      init_oneshot = sun_init;
+#endif
     } else if (!strcmp(backend_name, "opensl")) {
 #if defined(USE_OPENSL)
       init_oneshot = opensl_init;
@@ -190,6 +197,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
