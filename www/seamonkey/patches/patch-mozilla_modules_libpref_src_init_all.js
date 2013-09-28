$NetBSD: patch-mozilla_modules_libpref_src_init_all.js,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/modules/libpref/src/init/all.js.orig	2013-09-16 18:26:53.000000000 +0000
+++ mozilla/modules/libpref/src/init/all.js
@@ -188,7 +188,7 @@ pref("media.webm.enabled", true);
 pref("media.dash.enabled", false);
 #endif
 #ifdef MOZ_GSTREAMER
-pref("media.gstreamer.enabled", false);
+pref("media.gstreamer.enabled", true);
 #endif
 #ifdef MOZ_WEBRTC
 pref("media.navigator.enabled", true);
