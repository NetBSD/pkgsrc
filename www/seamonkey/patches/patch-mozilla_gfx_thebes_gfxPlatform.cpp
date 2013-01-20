$NetBSD: patch-mozilla_gfx_thebes_gfxPlatform.cpp,v 1.5 2013/01/20 08:33:14 ryoon Exp $

--- mozilla/gfx/thebes/gfxPlatform.cpp.orig	2013-01-06 06:26:16.000000000 +0000
+++ mozilla/gfx/thebes/gfxPlatform.cpp
@@ -507,11 +507,9 @@ void SourceBufferDestroy(void *srcSurfUD
   delete static_cast<SourceSurfaceUserData*>(srcSurfUD);
 }
 
-void SourceSnapshotDetached(cairo_surface_t *nullSurf)
+void SourceSnapshotDetached(void *nullSurf)
 {
-  gfxImageSurface* origSurf =
-    static_cast<gfxImageSurface*>(cairo_surface_get_user_data(nullSurf, &kSourceSurface));
-
+  gfxImageSurface *origSurf = static_cast<gfxImageSurface*>(nullSurf);
   origSurf->SetData(&kSourceSurface, NULL, NULL);
 }
 
@@ -626,14 +624,9 @@ gfxPlatform::GetSourceSurfaceForSurface(
 
     }
 
-    cairo_surface_t *nullSurf =
-	cairo_null_surface_create(CAIRO_CONTENT_COLOR_ALPHA);
-    cairo_surface_set_user_data(nullSurf,
-                                &kSourceSurface,
-                                imgSurface,
-                                NULL);
-    cairo_surface_attach_snapshot(imgSurface->CairoSurface(), nullSurf, SourceSnapshotDetached);
-    cairo_surface_destroy(nullSurf);
+    cairo_surface_set_mime_data(imgSurface->CairoSurface(), "mozilla/magic",
+                                (const unsigned char *) "data", 4,
+                                SourceSnapshotDetached, imgSurface.get());
   }
 
   SourceSurfaceUserData *srcSurfUD = new SourceSurfaceUserData;
