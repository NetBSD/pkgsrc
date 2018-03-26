$NetBSD: patch-modules_libpref_init_all.js,v 1.8 2018/03/26 22:24:45 maya Exp $

Else case same as linux for duplex audio, capture_delay, and disabling
custom styling to workaround a GTK bug

--- modules/libpref/init/all.js.orig	2018-03-10 02:54:17.000000000 +0000
+++ modules/libpref/init/all.js
@@ -532,7 +532,10 @@ pref("media.peerconnection.capture_delay
 pref("media.navigator.hardware.vp8_encode.acceleration_enabled", true);
 pref("media.navigator.hardware.vp8_encode.acceleration_remote_enabled", true);
 pref("media.navigator.hardware.vp8_decode.acceleration_enabled", false);
+#elif defined(XP_LINUX) || defined(MOZ_SNDIO)
+pref("media.peerconnection.capture_delay", 70);
 #else
+// *BSD, others - merely a guess for now
 pref("media.peerconnection.capture_delay", 70);
 #endif
 // Use MediaDataDecoder API for WebRTC, this includes hardware acceleration for
@@ -1331,8 +1334,8 @@ pref("dom.forms.autocomplete.formautofil
 // Enable search in <select> dropdowns (more than 40 options)
 pref("dom.forms.selectSearch", false);
 // Allow for webpages to provide custom styling for <select>
-// popups. Disabled on Linux due to bug 1338283.
-#ifdef XP_LINUX
+// popups. Disabled on GTK due to bug 1338283.
+#ifdef MOZ_WIDGET_GTK
 pref("dom.forms.select.customstyling", false);
 #else
 pref("dom.forms.select.customstyling", true);
