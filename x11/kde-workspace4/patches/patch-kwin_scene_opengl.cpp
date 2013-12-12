$NetBSD: patch-kwin_scene_opengl.cpp,v 1.1 2013/12/12 11:09:28 markd Exp $

Don't fail build with old MesaLib

--- kwin/scene_opengl.cpp.orig	2013-09-26 19:18:26.000000000 +0000
+++ kwin/scene_opengl.cpp
@@ -293,6 +293,7 @@ void SceneOpenGL::copyPixels(const QRegi
 }
 #endif
 
+#if GLX_GLXEXT_VERSION >= 32
 #ifndef KWIN_HAVE_OPENGLES
 #  define GL_GUILTY_CONTEXT_RESET_KWIN    GL_GUILTY_CONTEXT_RESET_ARB
 #  define GL_INNOCENT_CONTEXT_RESET_KWIN  GL_INNOCENT_CONTEXT_RESET_ARB
@@ -302,9 +303,11 @@ void SceneOpenGL::copyPixels(const QRegi
 #  define GL_INNOCENT_CONTEXT_RESET_KWIN  GL_INNOCENT_CONTEXT_RESET_EXT
 #  define GL_UNKNOWN_CONTEXT_RESET_KWIN   GL_UNKNOWN_CONTEXT_RESET_EXT
 #endif
+#endif
 
 void SceneOpenGL::handleGraphicsReset(GLenum status)
 {
+#if GLX_GLXEXT_VERSION >= 32
     switch (status) {
     case GL_GUILTY_CONTEXT_RESET_KWIN:
         kDebug(1212) << "A graphics reset attributable to the current GL context occurred.";
@@ -321,6 +324,7 @@ void SceneOpenGL::handleGraphicsReset(GL
     default:
         break;
     }
+#endif
 
     QElapsedTimer timer;
     timer.start();
