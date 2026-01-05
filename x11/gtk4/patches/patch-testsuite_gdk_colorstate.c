$NetBSD: patch-testsuite_gdk_colorstate.c,v 1.1 2026/01/05 14:08:23 adam Exp $

Fix build.

--- testsuite/gdk/colorstate.c.orig	2026-01-05 13:26:22.141849124 +0000
+++ testsuite/gdk/colorstate.c
@@ -166,7 +166,7 @@ test_convert (gconstpointer testdata,
                                         gdk_color_state_get_srgb ()));
   if (method == TEXTURE_METHOD_DMABUF)
     {
-#ifdef HAVE_DRM_FOURCC_H
+#if 0
       texture = udmabuf_texture_from_texture (texture, &error);
 #else
       g_assert_not_reached ();
