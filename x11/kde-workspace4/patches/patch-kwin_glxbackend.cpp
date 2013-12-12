$NetBSD: patch-kwin_glxbackend.cpp,v 1.1 2013/12/12 11:09:28 markd Exp $

Don't fail build with old MesaLib 

--- kwin/glxbackend.cpp.orig	2013-09-26 19:18:26.000000000 +0000
+++ kwin/glxbackend.cpp
@@ -152,6 +152,7 @@ bool GlxBackend::initRenderingContext()
 {
     bool direct = options->isGlDirect();
 
+#if GLX_GLXEXT_VERSION >= 32
     // Use glXCreateContextAttribsARB() when it's available
     if (glXCreateContextAttribsARB) {
         const int attribs_31_core_robustness[] = {
@@ -197,6 +198,7 @@ bool GlxBackend::initRenderingContext()
         if (!ctx)
             ctx = glXCreateContextAttribsARB(display(), fbconfig, 0, direct, attribs_legacy);
     }
+#endif
 
     if (!ctx)
         ctx = glXCreateNewContext(display(), fbconfig, GLX_RGBA_TYPE, NULL, direct);
