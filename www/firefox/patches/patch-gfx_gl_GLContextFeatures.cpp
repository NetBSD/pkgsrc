$NetBSD: patch-gfx_gl_GLContextFeatures.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/gl/GLContextFeatures.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/gl/GLContextFeatures.cpp
@@ -7,7 +7,7 @@
 #include "GLContext.h"
 #include "nsPrintfCString.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "nsCocoaFeatures.h"
 #endif
 
@@ -394,7 +394,7 @@ CanReadSRGBFromFBOTexture(GLContext* gl)
     if (!gl->WorkAroundDriverBugs())
         return true;
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // Bug 843668:
     // MacOSX 10.6 reports to support EXT_framebuffer_sRGB and
     // EXT_texture_sRGB but fails to convert from sRGB to linear
