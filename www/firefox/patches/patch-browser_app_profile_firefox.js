$NetBSD: patch-browser_app_profile_firefox.js,v 1.12 2019/02/01 16:47:59 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2019-01-24 18:48:38.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1770,6 +1770,15 @@ pref("toolkit.coverage.endpoint.base", "
 pref("prio.enabled", true);
 #endif
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
