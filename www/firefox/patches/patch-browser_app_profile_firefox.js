$NetBSD: patch-browser_app_profile_firefox.js,v 1.22 2023/11/03 10:20:03 ryoon Exp $

This patch modifies default Firefox settings - see the comments above
each one.

--- browser/app/profile/firefox.js.orig	2023-08-17 21:21:27.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -2340,6 +2340,36 @@ pref("app.normandy.onsync_skew_sec", 600
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
+// Firefox includes a complex mechanism for "blacklisting" GPUs that
+// appears to fail on a NetBSD system where the only available OpenGL
+// implementations are all from Mesa.  WebRender was supposed to be
+// enabled by default from Firefox 91 onwards and appears to greatly
+// improve performance even with acceleration disabled at the kernel
+// level.
+pref("gfx.webrender.all", true);
+
+// Disable Web MIDI support
+// NetBSD gets immediate SIGSEGV when Web MIDI is enabled.
+pref("midi.testing", true);
+pref("dom.webmidi.enabled", true);
+pref("midi.prompt.testing", true);
+pref("media.navigator.permission.disabled", true);
+
+// Avoid runtime error from WebGL for NetBSD systems
+pref("webgl.out-of-process", false);
+
+// On NetBSD, many web applications (e.g. Telegram, Mastodon, Twitter)
+// will freeze until the service worker is restarted in about:serviceworkers.
+// This is a workaround that makes most of these sites function.
+// The root cause of this should be investigated.
+pref("dom.serviceWorkers.enabled", false);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
