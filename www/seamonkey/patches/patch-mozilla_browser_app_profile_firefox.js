$NetBSD: patch-mozilla_browser_app_profile_firefox.js,v 1.3 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/browser/app/profile/firefox.js.orig	2020-04-01 11:01:50.000000000 +0000
+++ mozilla/browser/app/profile/firefox.js
@@ -1710,6 +1710,10 @@ pref("extensions.formautofill.available"
 pref("extensions.formautofill.available", "detect");
 #endif
 pref("extensions.formautofill.addresses.enabled", true);
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
 pref("extensions.formautofill.creditCards.enabled", true);
 pref("extensions.formautofill.firstTimeUse", true);
 pref("extensions.formautofill.heuristics.enabled", true);
