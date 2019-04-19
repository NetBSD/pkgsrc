$NetBSD: patch-mozilla-release_toolkit_xre_glxtest.cpp,v 1.1 2019/04/19 14:02:03 fox Exp $

Fix libGL filename on NetBSD,
see https://bugzilla.mozilla.org/show_bug.cgi?id=1180498

Original patch from matrin, imported from www/firefox

--- mozilla-release/toolkit/xre/glxtest.cpp.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/toolkit/xre/glxtest.cpp
@@ -116,7 +116,7 @@ void glxtest() {
         "The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
     ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #  define LIBGL_FILENAME "libGL.so"
 #else
 #  define LIBGL_FILENAME "libGL.so.1"
