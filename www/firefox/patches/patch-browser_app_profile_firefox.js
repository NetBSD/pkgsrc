$NetBSD: patch-browser_app_profile_firefox.js,v 1.14 2020/05/02 22:24:24 maya Exp $

--- browser/app/profile/firefox.js.orig	2019-07-06 01:48:29.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1851,6 +1851,17 @@ pref("fission.frontend.simulate-messages
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
+// WebGL broken without multiprocess window: https://bugzilla.mozilla.org/show_bug.cgi?id=1610395
+pref("webgl.disabled", true);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
