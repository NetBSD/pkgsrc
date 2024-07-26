$NetBSD: patch-platform_gfx_angle_src_libANGLE_renderer_gl_glx_FunctionsGLX.cpp,v 1.1 2024/07/26 08:05:23 nia Exp $

NetBSD also does not have the libGL.so.1 version.

--- platform/gfx/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp.orig	2024-07-25 22:12:46.396663262 +0000
+++ platform/gfx/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp
@@ -130,7 +130,11 @@ bool FunctionsGLX::initialize(Display *x
     // which a GLXWindow was ever created.
     if (!sLibHandle)
     {
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+        sLibHandle = dlopen("libGL.so", RTLD_NOW);
+#else
         sLibHandle = dlopen("libGL.so.1", RTLD_NOW);
+#endif
         if (!sLibHandle)
         {
             *errorString = std::string("Could not dlopen libGL.so.1: ") + dlerror();
