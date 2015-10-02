$NetBSD: patch-mozilla_toolkit_xre_glxtest.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/toolkit/xre/glxtest.cpp.orig	2015-09-25 07:35:13.000000000 +0000
+++ mozilla/toolkit/xre/glxtest.cpp
@@ -124,7 +124,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
