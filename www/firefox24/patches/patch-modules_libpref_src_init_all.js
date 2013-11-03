$NetBSD: patch-modules_libpref_src_init_all.js,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- modules/libpref/src/init/all.js.orig	2013-09-10 03:43:49.000000000 +0000
+++ modules/libpref/src/init/all.js
@@ -188,7 +188,7 @@ pref("media.webm.enabled", true);
 pref("media.dash.enabled", false);
 #endif
 #ifdef MOZ_GSTREAMER
-pref("media.gstreamer.enabled", false);
+pref("media.gstreamer.enabled", true);
 #endif
 #ifdef MOZ_WEBRTC
 pref("media.navigator.enabled", true);
