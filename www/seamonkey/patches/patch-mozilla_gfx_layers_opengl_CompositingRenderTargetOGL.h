$NetBSD: patch-mozilla_gfx_layers_opengl_CompositingRenderTargetOGL.h,v 1.1 2018/03/26 22:56:07 maya Exp $

CVE-2018-5148: Use-after-free in compositor

A use-after-free vulnerability can occur in the compositor during
certain graphics operations when a raw pointer is used instead of a
reference counted one. This results in a potentially exploitable crash

Bug 1440717 - Use RefPtr for CompositingRenderTargetOGL::mGL. r=Bas, a=ritu

--- mozilla/gfx/layers/opengl/CompositingRenderTargetOGL.h.orig	2018-02-05 11:48:08.000000000 +0000
+++ mozilla/gfx/layers/opengl/CompositingRenderTargetOGL.h
@@ -184,7 +184,7 @@ private:
    * the target is always cleared at the end of a frame.
    */
   RefPtr<CompositorOGL> mCompositor;
-  GLContext* mGL;
+  RefPtr<GLContext> mGL;
   GLuint mTextureHandle;
   GLuint mFBO;
 };
