$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- gfx/thebes/gfxPlatform.cpp.orig	2013-01-04 23:44:33.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
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
