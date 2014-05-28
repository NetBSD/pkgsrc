$NetBSD: patch-gfx_gl_GLContextProvider.h,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/gl/GLContextProvider.h.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/gl/GLContextProvider.h
@@ -33,7 +33,7 @@ namespace gl {
 #define DEFAULT_IMPL WGL
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #define GL_CONTEXT_PROVIDER_NAME GLContextProviderCGL
 #include "GLContextProviderImpl.h"
 #undef GL_CONTEXT_PROVIDER_NAME
