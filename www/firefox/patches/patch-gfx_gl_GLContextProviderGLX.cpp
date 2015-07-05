$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.1 2015/07/05 11:55:06 martin Exp $

Fix libGL.so filename on NetBSD,
see https://bugzilla.mozilla.org/show_bug.cgi?id=1180498

--- gfx/gl/GLContextProviderGLX.cpp.orig	2015-07-01 00:58:10.000000000 +0200
+++ gfx/gl/GLContextProviderGLX.cpp	2015-07-04 21:13:15.000000000 +0200
@@ -82,7 +82,7 @@
         // see e.g. bug 608526: it is intrinsically interesting to know whether we have dynamically linked to libGL.so.1
         // because at least the NVIDIA implementation requires an executable stack, which causes mprotect calls,
         // which trigger glibc bug http://sourceware.org/bugzilla/show_bug.cgi?id=12225
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         libGLfilename = "libGL.so";
 #else
         libGLfilename = "libGL.so.1";
