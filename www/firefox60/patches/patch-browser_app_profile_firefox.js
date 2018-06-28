$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2018/06/28 14:04:10 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2018-05-16 05:38:23.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1747,3 +1747,9 @@ pref("app.shield.optoutstudies.enabled",
 #else
 pref("app.shield.optoutstudies.enabled", false);
 #endif
+
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
