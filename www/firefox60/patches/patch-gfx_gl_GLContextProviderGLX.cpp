$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.1 2019/06/01 15:01:39 wiz Exp $

NetBSD doesn't ship libGL.so.1 due to a major bump. Look for the unversioned
name.

--- gfx/gl/GLContextProviderGLX.cpp.orig	2019-05-14 19:13:16.000000000 +0000
+++ gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // implementation requires an executable stack, which causes mprotect calls,
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #else
     libGLfilename = "libGL.so.1";
