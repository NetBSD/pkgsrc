$NetBSD: patch-media_libcubeb_src_cubeb.c,v 1.1 2017/04/27 01:55:57 ryoon Exp $

* Support OSS audio

--- media/libcubeb/src/cubeb.c.orig	2017-01-23 16:13:54.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -54,6 +54,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 
 static int
@@ -141,6 +144,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
