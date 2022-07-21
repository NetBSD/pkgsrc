$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2022/07/21 23:56:39 nia Exp $

This patch modifies default Firefox settings - see the comments above
each one.

--- browser/app/profile/firefox.js.orig	2022-04-28 23:01:46.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -2205,6 +2205,20 @@ pref("fission.frontend.simulate-messages
 pref("toolkit.coverage.enabled", false);
 pref("toolkit.coverage.endpoint.base", "https://coverage.mozilla.org");
 
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
+
+// Enable system addons, for example langpacks from www/firefox-l10n
+pref("extensions.autoDisableScopes", 11);
+
+// Firefox includes a complex mechanism for "blacklisting" GPUs that
+// appears to fail on a NetBSD system where the only available OpenGL
+// implementations are all from Mesa.  WebRender was supposed to be
+// enabled by default from Firefox 91 onwards and appears to greatly
+// improve performance even with acceleration disabled at the kernel
+// level.
+pref("gfx.webrender.all", true);
+
 // Discovery prefs
 pref("browser.discovery.enabled", true);
 pref("browser.discovery.containers.enabled", true);
