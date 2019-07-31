$NetBSD: patch-mozilla-release_browser_app_profile_firefox.js,v 1.2 2019/07/31 01:35:27 fox Exp $

1. Pickup LANG/LC_MESSAGE from environment.
2. Disable multiprocess window support. Refer PR 53273

Original patch from ryoon, imported from www/firefox

--- mozilla-release/browser/app/profile/firefox.js.orig	2019-07-06 01:48:29.000000000 +0000
+++ mozilla-release/browser/app/profile/firefox.js
@@ -1865,6 +1865,15 @@ pref("prio.publicKeyB", "26E6674E65425B8
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
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
