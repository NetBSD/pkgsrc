$NetBSD: patch-platform_gfx_gl_GLContextProviderGLX.cpp,v 1.1 2024/07/26 08:05:23 nia Exp $

NetBSD also does not have the libGL.so.1 version.

--- platform/gfx/gl/GLContextProviderGLX.cpp.orig	2024-07-25 14:39:31.230121830 +0000
+++ platform/gfx/gl/GLContextProviderGLX.cpp
@@ -84,7 +84,7 @@ GLXLibrary::EnsureInitialized()
         // see e.g. bug 608526: it is intrinsically interesting to know whether we have dynamically linked to libGL.so.1
         // because at least the NVIDIA implementation requires an executable stack, which causes mprotect calls,
         // which trigger glibc bug http://sourceware.org/bugzilla/show_bug.cgi?id=12225
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         libGLfilename = "libGL.so";
 #else
         libGLfilename = "libGL.so.1";
