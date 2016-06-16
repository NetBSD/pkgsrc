$NetBSD: patch-modules_libpref_init_all.js,v 1.4 2016/06/16 12:08:21 ryoon Exp $

* Improve stability under NetBSD.

--- modules/libpref/init/all.js.orig	2016-06-01 04:11:44.000000000 +0000
+++ modules/libpref/init/all.js
@@ -4417,7 +4417,7 @@ pref("layers.max-active", -1);
 pref("layers.tiles.adjust", true);
 
 // Set the default values, and then override per-platform as needed
-pref("layers.offmainthreadcomposition.enabled", true);
+pref("layers.offmainthreadcomposition.enabled", false);
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
@@ -4504,7 +4504,7 @@ pref("device.sensors.enabled", true);
 pref("device.storage.enabled", false);
 
 // Toggle which thread the HTML5 parser uses for stream parsing
-pref("html5.offmainthread", true);
+pref("html5.offmainthread", false);
 // Time in milliseconds between the time a network buffer is seen and the
 // timer firing when the timer hasn't fired previously in this parse in the
 // off-the-main-thread HTML5 parser.
