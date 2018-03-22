$NetBSD: patch-modules_libpref_init_all.js,v 1.7.2.2 2018/03/22 06:56:21 spz Exp $

--- modules/libpref/init/all.js.orig	2018-03-10 02:54:17.000000000 +0000
+++ modules/libpref/init/all.js
@@ -522,25 +522,18 @@ pref("media.getusermedia.agc", 3); // kA
 // capture_delay: Adjustments for OS-specific input delay (lower bound)
 // playout_delay: Adjustments for OS-specific AudioStream+cubeb+output delay (lower bound)
 // full_duplex: enable cubeb full-duplex capture/playback
+pref("media.navigator.audio.full_duplex", true);
 #if defined(XP_MACOSX)
 pref("media.peerconnection.capture_delay", 50);
-pref("media.navigator.audio.full_duplex", true);
 #elif defined(XP_WIN)
 pref("media.peerconnection.capture_delay", 50);
-pref("media.navigator.audio.full_duplex", true);
 #elif defined(ANDROID)
 pref("media.peerconnection.capture_delay", 100);
-pref("media.navigator.audio.full_duplex", true);
 pref("media.navigator.hardware.vp8_encode.acceleration_enabled", true);
 pref("media.navigator.hardware.vp8_encode.acceleration_remote_enabled", true);
 pref("media.navigator.hardware.vp8_decode.acceleration_enabled", false);
-#elif defined(XP_LINUX) || defined(MOZ_SNDIO)
-pref("media.peerconnection.capture_delay", 70);
-pref("media.navigator.audio.full_duplex", true);
 #else
-// *BSD, others - merely a guess for now
-pref("media.peerconnection.capture_delay", 50);
-pref("media.navigator.audio.full_duplex", false);
+pref("media.peerconnection.capture_delay", 70);
 #endif
 // Use MediaDataDecoder API for WebRTC, this includes hardware acceleration for
 // decoding.
@@ -1338,8 +1331,8 @@ pref("dom.forms.autocomplete.formautofil
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
