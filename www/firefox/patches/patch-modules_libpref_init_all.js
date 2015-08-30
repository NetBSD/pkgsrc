$NetBSD: patch-modules_libpref_init_all.js,v 1.1 2015/08/30 09:29:15 ryoon Exp $

--- modules/libpref/init/all.js.orig	2015-08-26 09:39:08.000000000 +0000
+++ modules/libpref/init/all.js
@@ -4048,7 +4048,7 @@ pref("layers.max-active", -1);
 pref("layers.tiles.adjust", true);
 
 // Set the default values, and then override per-platform as needed
-pref("layers.offmainthreadcomposition.enabled", true);
+pref("layers.offmainthreadcomposition.enabled", false);
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
