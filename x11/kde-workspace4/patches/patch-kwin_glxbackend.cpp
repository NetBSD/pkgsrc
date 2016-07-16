$NetBSD: patch-kwin_glxbackend.cpp,v 1.2 2016/07/16 00:47:00 markd Exp $

fixes for gcc6 from opensuse
Don't fail build with old MesaLib 

--- kwin/glxbackend.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ kwin/glxbackend.cpp
@@ -45,7 +45,7 @@ GlxBackend::GlxBackend()
     , window(None)
     , fbconfig(NULL)
     , glxWindow(None)
-    , ctx(None)
+    , ctx(NULL)
     , m_bufferAge(0)
     , haveSwapInterval(false)
 {
@@ -164,6 +164,7 @@ bool GlxBackend::initRenderingContext()
 {
     bool direct = options->isGlDirect();
 
+#if GLX_GLXEXT_VERSION >= 32
     // Use glXCreateContextAttribsARB() when it's available
     if (glXCreateContextAttribsARB) {
         const int attribs_31_core_robustness[] = {
@@ -209,6 +210,7 @@ bool GlxBackend::initRenderingContext()
         if (!ctx)
             ctx = glXCreateContextAttribsARB(display(), fbconfig, 0, direct, attribs_legacy);
     }
+#endif
 
     if (!ctx)
         ctx = glXCreateNewContext(display(), fbconfig, GLX_RGBA_TYPE, NULL, direct);
