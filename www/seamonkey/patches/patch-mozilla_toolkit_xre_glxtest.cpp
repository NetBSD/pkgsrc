$NetBSD: patch-mozilla_toolkit_xre_glxtest.cpp,v 1.2 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/toolkit/xre/glxtest.cpp.orig	2020-02-17 23:39:44.000000000 +0000
+++ mozilla/toolkit/xre/glxtest.cpp
@@ -124,7 +124,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
