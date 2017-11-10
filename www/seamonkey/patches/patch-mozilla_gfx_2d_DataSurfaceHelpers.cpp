$NetBSD: patch-mozilla_gfx_2d_DataSurfaceHelpers.cpp,v 1.1 2017/11/10 22:45:27 ryoon Exp $

--- mozilla/gfx/2d/DataSurfaceHelpers.cpp.orig	2017-10-16 07:17:49.000000000 +0000
+++ mozilla/gfx/2d/DataSurfaceHelpers.cpp
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
