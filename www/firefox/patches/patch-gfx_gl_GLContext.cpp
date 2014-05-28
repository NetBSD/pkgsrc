$NetBSD: patch-gfx_gl_GLContext.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/gl/GLContext.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/gl/GLContext.cpp
@@ -34,12 +34,9 @@
 #include "mozilla/DebugOnly.h"
 #include "mozilla/Preferences.h"
 
-#ifdef XP_MACOSX
+#if defined(MOZ_WIDGET_COCOA)
 #include <CoreServices/CoreServices.h>
 #include "gfxColor.h"
-#endif
-
-#if defined(MOZ_WIDGET_COCOA)
 #include "nsCocoaFeatures.h"
 #endif
 
@@ -610,7 +607,7 @@ GLContext::InitWithPrefix(const char *pr
                 MarkUnsupported(GLFeature::standard_derivatives);
             }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
             // The Mac Nvidia driver, for versions up to and including 10.8, don't seem
             // to properly support this.  See 814839
             // this has been fixed in Mac OS X 10.9. See 907946
@@ -1050,7 +1047,7 @@ GLContext::InitWithPrefix(const char *pr
         raw_fGetIntegerv(LOCAL_GL_MAX_CUBE_MAP_TEXTURE_SIZE, &mMaxCubeMapTextureSize);
         raw_fGetIntegerv(LOCAL_GL_MAX_RENDERBUFFER_SIZE, &mMaxRenderbufferSize);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         if (mWorkAroundDriverBugs) {
             if (mVendor == GLVendor::Intel) {
                 // see bug 737182 for 2D textures, bug 684882 for cube map textures.
