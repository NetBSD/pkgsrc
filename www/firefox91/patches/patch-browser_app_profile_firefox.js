$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2021/09/08 22:19:50 nia Exp $

--- browser/app/profile/firefox.js.orig	2019-07-06 01:48:29.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1851,6 +1851,12 @@ pref("fission.frontend.simulate-messages
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
