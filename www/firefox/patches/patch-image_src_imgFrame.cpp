$NetBSD: patch-image_src_imgFrame.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- image/src/imgFrame.cpp.orig	2014-05-06 22:55:36.000000000 +0000
+++ image/src/imgFrame.cpp
@@ -54,7 +54,7 @@ static bool AllowedImageSize(int32_t aWi
     NS_WARNING("width or height too large");
     return false;
   }
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   // CoreGraphics is limited to images < 32K in *height*, so clamp all surfaces on the Mac to that height
   if (MOZ_UNLIKELY(aHeight > SHRT_MAX)) {
     NS_WARNING("image too big");
@@ -190,7 +190,7 @@ nsresult imgFrame::Init(int32_t aX, int3
       return NS_ERROR_OUT_OF_MEMORY;
     }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     if (!ShouldUseImageSurfaces()) {
       mQuartzSurface = new gfxQuartzImageSurface(mImageSurface);
     }
@@ -254,7 +254,7 @@ nsresult imgFrame::Optimize()
 #ifdef USE_WIN_SURFACE
         mWinSurface = nullptr;
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         mQuartzSurface = nullptr;
 #endif
 
@@ -288,7 +288,7 @@ nsresult imgFrame::Optimize()
   }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (mQuartzSurface) {
     mQuartzSurface->Flush();
   }
@@ -302,7 +302,7 @@ nsresult imgFrame::Optimize()
 #ifdef USE_WIN_SURFACE
     mWinSurface = nullptr;
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     mQuartzSurface = nullptr;
 #endif
   }
@@ -586,7 +586,7 @@ nsresult imgFrame::LockImageData()
 #ifdef USE_WIN_SURFACE
     mWinSurface = nullptr;
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     mQuartzSurface = nullptr;
 #endif
   }
@@ -649,7 +649,7 @@ nsresult imgFrame::UnlockImageData()
     mWinSurface->MarkDirty();
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // The quartz image surface (ab)uses the flush method to get the
   // cairo_image_surface data into a CGImage, so we have to call Flush() here.
   if (mQuartzSurface)
@@ -684,7 +684,7 @@ void imgFrame::ApplyDirtToSurfaces()
       mWinSurface->MarkDirty();
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // The quartz image surface (ab)uses the flush method to get the
     // cairo_image_surface data into a CGImage, so we have to call Flush() here.
     if (mQuartzSurface)
@@ -791,7 +791,7 @@ imgFrame::SizeOfExcludingThisWithCompute
     n += mWinSurface->KnownMemoryUsed();
   } else
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (mQuartzSurface && aLocation == gfxMemoryLocation::IN_PROCESS_HEAP) {
     n += mSize.width * mSize.height * 4;
   } else
