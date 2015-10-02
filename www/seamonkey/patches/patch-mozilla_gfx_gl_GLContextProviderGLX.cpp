$NetBSD: patch-mozilla_gfx_gl_GLContextProviderGLX.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/gfx/gl/GLContextProviderGLX.cpp.orig	2015-09-25 07:36:44.000000000 +0000
+++ mozilla/gfx/gl/GLContextProviderGLX.cpp
@@ -82,7 +82,7 @@ GLXLibrary::EnsureInitialized()
         // see e.g. bug 608526: it is intrinsically interesting to know whether we have dynamically linked to libGL.so.1
         // because at least the NVIDIA implementation requires an executable stack, which causes mprotect calls,
         // which trigger glibc bug http://sourceware.org/bugzilla/show_bug.cgi?id=12225
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         libGLfilename = "libGL.so";
 #else
         libGLfilename = "libGL.so.1";
