$NetBSD: patch-gfx_2d_Factory.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/2d/Factory.cpp.orig	2014-05-06 22:55:32.000000000 +0000
+++ gfx/2d/Factory.cpp
@@ -23,12 +23,8 @@
 #include "ScaledFontWin.h"
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "ScaledFontMac.h"
-#endif
-
-
-#ifdef XP_MACOSX
 #include "DrawTargetCG.h"
 #endif
 
@@ -258,7 +254,7 @@ Factory::CreateDrawTarget(BackendType aB
       break;
     }
 #endif
-#elif defined XP_MACOSX
+#elif defined MOZ_WIDGET_COCOA
   case BackendType::COREGRAPHICS:
   case BackendType::COREGRAPHICS_ACCELERATED:
     {
@@ -340,7 +336,7 @@ Factory::CreateDrawTargetForData(Backend
       retVal = newTarget;
     }
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   case BackendType::COREGRAPHICS:
     {
       RefPtr<DrawTargetCG> newTarget = new DrawTargetCG();
@@ -393,7 +389,7 @@ Factory::CreateScaledFontForNativeFont(c
     }
 #endif
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   case NativeFontType::MAC_FONT_FACE:
     {
       return new ScaledFontMac(static_cast<CGFontRef>(aNativeFont.mFont), aSize);
@@ -656,7 +652,7 @@ Factory::CreateSourceSurfaceForCairoSurf
   return retVal;
 }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 TemporaryRef<DrawTarget>
 Factory::CreateDrawTargetForCairoCGContext(CGContextRef cg, const IntSize& aSize)
 {
