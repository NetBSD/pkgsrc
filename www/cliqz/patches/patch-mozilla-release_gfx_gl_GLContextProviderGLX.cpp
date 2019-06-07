$NetBSD: patch-mozilla-release_gfx_gl_GLContextProviderGLX.cpp,v 1.1 2019/06/07 01:19:07 fox Exp $

NetBSD doesn't ship libGL.so.1 due to a major bump. Look for the unversioned
name.
https://hg.mozilla.org/integration/mozilla-inbound/rev/8bcc51aaa91e

Original patch from maya, imported from www/firefox

--- mozilla-release/gfx/gl/GLContextProviderGLX.cpp.orig	2019-06-06 19:46:11.548358853 +0000
+++ mozilla-release/gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
     const char* libGLfilename = "libGL.so.1";
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #endif
 
