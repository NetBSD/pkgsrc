$NetBSD: patch-third__party_angle_src_libANGLE_renderer_gl_glx_FunctionsGLX.cpp,v 1.20 2026/06/01 10:09:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp.orig	2026-05-26 20:39:02.000000000 +0000
+++ third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp
@@ -153,10 +153,10 @@ bool FunctionsGLX::initialize(Display *x
     // which a GLXWindow was ever created.
     if (!sLibHandle)
     {
-        sLibHandle = dlopen("libGL.so.1", RTLD_NOW);
+        sLibHandle = dlopen("libGL.so", RTLD_NOW);
         if (!sLibHandle)
         {
-            *errorString = std::string("Could not dlopen libGL.so.1: ") + dlerror();
+            *errorString = std::string("Could not dlopen libGL.so: ") + dlerror();
             return false;
         }
     }
