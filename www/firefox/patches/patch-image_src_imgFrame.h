$NetBSD: patch-image_src_imgFrame.h,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- image/src/imgFrame.h.orig	2014-05-06 22:55:36.000000000 +0000
+++ image/src/imgFrame.h
@@ -17,7 +17,7 @@
 #include "gfxImageSurface.h"
 #if defined(XP_WIN)
 #include "gfxWindowsSurface.h"
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
 #include "gfxQuartzImageSurface.h"
 #endif
 #include "nsAutoPtr.h"
@@ -96,7 +96,7 @@ public:
 #if defined(XP_WIN)
     if (mWinSurface)
       return mWinSurface;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
     if (mQuartzSurface)
       return mQuartzSurface;
 #endif
@@ -141,7 +141,7 @@ private: // data
   nsRefPtr<gfxASurface> mOptSurface;
 #if defined(XP_WIN)
   nsRefPtr<gfxWindowsSurface> mWinSurface;
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
   nsRefPtr<gfxQuartzImageSurface> mQuartzSurface;
 #endif
 
