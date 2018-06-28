$NetBSD: patch-browser_app_profile_firefox.js,v 1.8 2018/06/28 13:52:37 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2018-06-21 20:03:42.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1737,6 +1737,12 @@ pref("app.shield.optoutstudies.enabled",
 pref("app.shield.optoutstudies.enabled", false);
 #endif
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
 // Savant Shield study preferences
 pref("shield.savant.enabled", false);
 pref("shield.savant.loglevel", "warn");
