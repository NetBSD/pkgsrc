$NetBSD: patch-gfx_2d_DataSurfaceHelpers.cpp,v 1.1 2017/09/13 10:03:47 martin Exp $

On big endian platforms this happens a lot - swap an application crash
for slightly broken display while we are still hunting the real bug.

--- gfx/2d/DataSurfaceHelpers.cpp.orig	2017-04-11 04:13:04.000000000 +0200
+++ gfx/2d/DataSurfaceHelpers.cpp	2017-09-13 11:29:20.039199172 +0200
@@ -320,6 +320,12 @@ CopyRect(DataSourceSurface* aSrc, DataSo
     MOZ_CRASH("GFX: we should never be getting invalid rects at this point");
   }
 
+#if MOZ_BIG_ENDIAN
+  // hack: avoid a crash, we cope with the bogus display result for now
+  if (aSrc->GetFormat() != aDest->GetFormat())
+    return false;
+#endif
+
   MOZ_RELEASE_ASSERT(aSrc->GetFormat() == aDest->GetFormat(),
                      "GFX: different surface formats");
   MOZ_RELEASE_ASSERT(IntRect(IntPoint(), aSrc->GetSize()).Contains(aSrcRect),
