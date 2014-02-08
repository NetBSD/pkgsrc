$NetBSD: patch-browser_app_profile_firefox.js,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- browser/app/profile/firefox.js.orig	2014-01-28 04:03:33.000000000 +0000
+++ browser/app/profile/firefox.js
@@ -393,6 +393,7 @@ pref("browser.search.log", false);
 pref("browser.search.order.1",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.2",                "chrome://browser-region/locale/region.properties");
 pref("browser.search.order.3",                "chrome://browser-region/locale/region.properties");
+pref("browser.search.order.4",                "chrome://browser-region/locale/region.properties");
 
 // search bar results always open in a new tab
 pref("browser.search.openintab", false);
