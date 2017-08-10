$NetBSD: patch-browser_components_nsBrowserGlue.js,v 1.3 2017/08/10 14:46:15 ryoon Exp $

--- browser/components/nsBrowserGlue.js.orig	2017-07-31 16:20:47.000000000 +0000
+++ browser/components/nsBrowserGlue.js
@@ -532,9 +532,7 @@ BrowserGlue.prototype = {
     os.addObserver(this, "distribution-customization-complete");
     os.addObserver(this, "handle-xul-text-link");
     os.addObserver(this, "profile-before-change");
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      os.addObserver(this, "keyword-search");
-    }
+    os.addObserver(this, "keyword-search");
     os.addObserver(this, "browser-search-engine-modified");
     os.addObserver(this, "restart-in-safe-mode");
     os.addObserver(this, "flash-plugin-hang");
@@ -587,9 +585,7 @@ BrowserGlue.prototype = {
       os.removeObserver(this, "places-database-locked");
     os.removeObserver(this, "handle-xul-text-link");
     os.removeObserver(this, "profile-before-change");
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      os.removeObserver(this, "keyword-search");
-    }
+    os.removeObserver(this, "keyword-search");
     os.removeObserver(this, "browser-search-engine-modified");
     os.removeObserver(this, "flash-plugin-hang");
     os.removeObserver(this, "xpi-signature-changed");
