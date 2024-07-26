$NetBSD: patch-platform_toolkit_xre_glxtest.cpp,v 1.1 2024/07/26 08:05:23 nia Exp $

NetBSD does not have the libGL.so.1 version.

--- platform/toolkit/xre/glxtest.cpp.orig	2024-07-25 22:12:30.934622714 +0000
+++ platform/toolkit/xre/glxtest.cpp
@@ -161,7 +161,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
