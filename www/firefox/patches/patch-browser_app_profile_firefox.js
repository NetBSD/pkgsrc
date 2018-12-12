$NetBSD: patch-browser_app_profile_firefox.js,v 1.10 2018/12/12 14:08:50 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2018-12-07 02:56:20.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1796,3 +1796,9 @@ pref("toolkit.coverage.endpoint.base", "
 #if defined(NIGHTLY_BUILD) && defined(MOZ_LIBPRIO)
 pref("prio.enabled", true);
 #endif
+
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Disable multiprocess window support. Workaround for PR 53273.
+pref("browser.tabs.remote.autostart", false);
