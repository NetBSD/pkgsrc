$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.4 2019/06/04 00:23:11 maya Exp $

Fix libGL filename on NetBSD,
see https://bugzilla.mozilla.org/show_bug.cgi?id=1180498
https://hg.mozilla.org/integration/mozilla-inbound/rev/8bcc51aaa91e

--- toolkit/xre/glxtest.cpp.orig	2019-03-07 16:53:43.000000000 +0000
+++ toolkit/xre/glxtest.cpp
@@ -116,7 +116,7 @@ void glxtest() {
         "The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
     ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #  define LIBGL_FILENAME "libGL.so"
 #else
 #  define LIBGL_FILENAME "libGL.so.1"
