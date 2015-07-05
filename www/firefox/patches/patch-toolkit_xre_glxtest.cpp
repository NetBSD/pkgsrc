$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.1 2015/07/05 11:55:06 martin Exp $

Fix libGL filename on NetBSD,
see https://bugzilla.mozilla.org/show_bug.cgi?id=1180498

--- toolkit/xre/glxtest.cpp.orig	2015-07-04 20:26:15.000000000 +0200
+++ toolkit/xre/glxtest.cpp	2015-07-04 20:26:15.000000000 +0200
@@ -124,7 +124,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
