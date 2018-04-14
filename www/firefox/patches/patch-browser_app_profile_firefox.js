$NetBSD: patch-browser_app_profile_firefox.js,v 1.5 2018/04/14 07:05:14 ryoon Exp $

* Automatically set your UI language from LANG/LC_MESSAGE

--- browser/app/profile/firefox.js.orig	2018-03-22 20:46:41.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -1757,3 +1757,6 @@ pref("browser.onboarding.updatetour", "p
 
 // Preference that allows individual users to disable Screenshots.
 pref("extensions.screenshots.disabled", false);
+
+// Select UI locale from LANG/LC_MESSAGE environmental variables
+pref("intl.locale.requested", "");
