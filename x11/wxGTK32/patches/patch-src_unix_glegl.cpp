$NetBSD: patch-src_unix_glegl.cpp,v 1.1 2023/12/11 16:25:47 jperkin Exp $

Fix non-wayland build.

--- src/unix/glegl.cpp.orig	2023-12-11 16:01:26.158197607 +0000
+++ src/unix/glegl.cpp
@@ -810,6 +810,7 @@ bool wxGLCanvasEGL::SwapBuffers()
     // entire application completely unusable just because one of its windows
     // using wxGLCanvas got occluded or unmapped (e.g. due to a move to another
     // workspace).
+#ifdef GDK_WINDOWING_WAYLAND
     if ( !gs_alreadySetSwapInterval.count(this) )
     {
         // Ensure that eglSwapBuffers() doesn't block, as we use the surface
@@ -827,6 +828,7 @@ bool wxGLCanvasEGL::SwapBuffers()
                        this, eglGetError());
         }
     }
+#endif
 
     GdkWindow* const window = GTKGetDrawingWindow();
 #ifdef GDK_WINDOWING_X11
