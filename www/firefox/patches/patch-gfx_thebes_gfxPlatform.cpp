$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.3 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/thebes/gfxPlatform.cpp.orig	2014-05-06 22:55:35.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -30,7 +30,7 @@
 #if defined(XP_WIN)
 #include "gfxWindowsPlatform.h"
 #include "gfxD2DSurface.h"
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include "gfxPlatformMac.h"
 #include "gfxQuartzSurface.h"
 #elif defined(MOZ_WIDGET_GTK)
@@ -398,7 +398,7 @@ gfxPlatform::Init()
 
 #if defined(XP_WIN)
     gPlatform = new gfxWindowsPlatform;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     gPlatform = new gfxPlatformMac;
 #elif defined(MOZ_WIDGET_GTK)
     gPlatform = new gfxPlatformGtk;
@@ -432,7 +432,7 @@ gfxPlatform::Init()
 
     nsresult rv;
 
-#if defined(XP_MACOSX) || defined(XP_WIN) || defined(ANDROID) // temporary, until this is implemented on others
+#if defined(MOZ_WIDGET_COCOA) || defined(XP_WIN) || defined(ANDROID) // temporary, until this is implemented on others
     rv = gfxPlatformFontList::Init();
     if (NS_FAILED(rv)) {
         NS_RUNTIMEABORT("Could not initialize gfxPlatformFontList");
@@ -518,7 +518,7 @@ gfxPlatform::Shutdown()
     gfxFontGroup::Shutdown();
     gfxGradientCache::Shutdown();
     gfxGraphiteShaper::Shutdown();
-#if defined(XP_MACOSX) || defined(XP_WIN) // temporary, until this is implemented on others
+#if defined(MOZ_WIDGET_COCOA) || defined(XP_WIN) // temporary, until this is implemented on others
     gfxPlatformFontList::Shutdown();
 #endif
 
@@ -664,7 +664,7 @@ gfxPlatform::CreateDrawTargetForSurface(
 RefPtr<DrawTarget>
 gfxPlatform::CreateDrawTargetForUpdateSurface(gfxASurface *aSurface, const IntSize& aSize)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // this is a bit of a hack that assumes that the buffer associated with the CGContext
   // will live around long enough that nothing bad will happen.
   if (aSurface->GetType() == gfxSurfaceType::Quartz) {
