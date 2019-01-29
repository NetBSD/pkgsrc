$NetBSD: patch-browser_app_profile_firefox.js,v 1.11 2019/01/29 16:28:22 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2019-01-18 00:20:22.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1770,6 +1770,12 @@ pref("toolkit.coverage.endpoint.base", "
 pref("prio.enabled", true);
 #endif
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
