$NetBSD: patch-mozilla_gfx_layers_opengl_CompositingRenderTargetOGL.cpp,v 1.1 2018/03/26 22:56:07 maya Exp $

CVE-2018-5148: Use-after-free in compositor

A use-after-free vulnerability can occur in the compositor during
certain graphics operations when a raw pointer is used instead of a
reference counted one. This results in a potentially exploitable crash

Bug 1440717 - Use RefPtr for CompositingRenderTargetOGL::mGL. r=Bas, a=ritu

--- mozilla/gfx/layers/opengl/CompositingRenderTargetOGL.cpp.orig	2018-02-05 11:48:12.000000000 +0000
+++ mozilla/gfx/layers/opengl/CompositingRenderTargetOGL.cpp
@@ -60,7 +60,7 @@ CompositingRenderTargetOGL::BindRenderTa
         msg.AppendPrintf("Framebuffer not complete -- CheckFramebufferStatus returned 0x%x, "
                          "GLContext=%p, IsOffscreen()=%d, mFBO=%d, aFBOTextureTarget=0x%x, "
                          "aRect.width=%d, aRect.height=%d",
-                         result, mGL, mGL->IsOffscreen(), mFBO, mInitParams.mFBOTextureTarget,
+                         result, mGL.get(), mGL->IsOffscreen(), mFBO, mInitParams.mFBOTextureTarget,
                          mInitParams.mSize.width, mInitParams.mSize.height);
         NS_WARNING(msg.get());
       }
