$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.3 2019/05/31 10:38:59 maya Exp $

NetBSD doesn't ship libGL.so.1 due to a major bump. Look for the unversioned
name.

--- gfx/gl/GLContextProviderGLX.cpp.orig	2019-05-17 00:33:26.000000000 +0000
+++ gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
     const char* libGLfilename = "libGL.so.1";
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #endif
 
