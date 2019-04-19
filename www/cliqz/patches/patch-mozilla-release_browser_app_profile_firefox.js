$NetBSD: patch-mozilla-release_browser_app_profile_firefox.js,v 1.1 2019/04/19 14:02:03 fox Exp $

1. Pickup LANG/LC_MESSAGE from environment.
2. Disable multiprocess window support. Refer PR 53273

Original patch from ryoon, imported from www/firefox

--- mozilla-release/browser/app/profile/firefox.js.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/browser/app/profile/firefox.js
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
