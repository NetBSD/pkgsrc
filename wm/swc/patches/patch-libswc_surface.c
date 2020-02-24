$NetBSD: patch-libswc_surface.c,v 1.1 2020/02/24 12:31:20 nia Exp $

Don't error if the transformation type is "normal".

--- libswc/surface.c.orig	2020-02-22 10:04:33.000000000 +0000
+++ libswc/surface.c
@@ -268,7 +268,10 @@ commit(struct wl_client *client, struct 
 static void
 set_buffer_transform(struct wl_client *client, struct wl_resource *surface, int32_t transform)
 {
-	wl_resource_post_error(surface, WL_SURFACE_ERROR_INVALID_TRANSFORM, "buffer transform not supported");
+	if (transform != WL_OUTPUT_TRANSFORM_NORMAL) {
+		wl_resource_post_error(surface, WL_SURFACE_ERROR_INVALID_TRANSFORM,
+					"buffer transform %#" PRIx32 " not supported", transform);
+	}
 }
 
 static void
