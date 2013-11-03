$NetBSD: patch-browser_app_profile_firefox.js,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2013-09-10 03:43:20.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -354,6 +354,7 @@ pref("browser.search.log", false);
 pref("browser.search.order.1",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.2",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.3",                "chrome://browser-region/locale/region.properties");
+pref("browser.search.order.4",                "chrome://browser-region/locale/region.properties");
 
 // search bar results always open in a new tab
 pref("browser.search.openintab", false);
