$NetBSD: patch-browser_app_profile_firefox.js,v 1.9 2018/11/04 00:38:44 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2018-10-18 20:06:03.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1781,3 +1781,9 @@ pref("prio.publicKeyB", "26E6674E65425B8
 pref("browser.fastblock.enabled", true);
 #endif
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
