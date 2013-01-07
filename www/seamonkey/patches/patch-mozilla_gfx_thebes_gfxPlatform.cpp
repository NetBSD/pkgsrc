$NetBSD: patch-mozilla_gfx_thebes_gfxPlatform.cpp,v 1.4 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/gfx/thebes/gfxPlatform.cpp.orig	2012-11-18 10:19:37.000000000 +0000
+++ mozilla/gfx/thebes/gfxPlatform.cpp
@@ -490,6 +490,7 @@ void SourceBufferDestroy(void *srcBuffer
   static_cast<SourceSurface*>(srcBuffer)->Release();
 }
 
+#ifdef MOZ_TREE_CAIRO
 void SourceSnapshotDetached(cairo_surface_t *nullSurf)
 {
   gfxImageSurface* origSurf =
@@ -497,6 +498,7 @@ void SourceSnapshotDetached(cairo_surfac
 
   origSurf->SetData(&kSourceSurface, NULL, NULL);
 }
+#endif
 
 RefPtr<SourceSurface>
 gfxPlatform::GetSourceSurfaceForSurface(DrawTarget *aTarget, gfxASurface *aSurface)
@@ -594,6 +596,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
 
     }
 
+    #ifdef MOZ_TREE_CAIRO
     cairo_surface_t *nullSurf =
 	cairo_null_surface_create(CAIRO_CONTENT_COLOR_ALPHA);
     cairo_surface_set_user_data(nullSurf,
@@ -602,6 +605,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
                                 NULL);
     cairo_surface_attach_snapshot(imgSurface->CairoSurface(), nullSurf, SourceSnapshotDetached);
     cairo_surface_destroy(nullSurf);
+    #endif
   }
 
   srcBuffer->AddRef();
