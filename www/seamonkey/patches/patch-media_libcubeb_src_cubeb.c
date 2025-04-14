$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.1 2025/04/14 15:33:04 nia Exp $

- Sun Audio support.

--- media/libcubeb/src/cubeb.c.orig	2025-03-07 15:42:46.304248718 +0000
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
@@ -148,6 +151,10 @@ cubeb_init(cubeb ** context, char const 
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
@@ -195,6 +202,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_SNDIO)
     sndio_init,
 #endif
+#if defined(USE_SUN)
+    sun_init,
+#endif
 #if defined(USE_OPENSL)
     opensl_init,
 #endif
