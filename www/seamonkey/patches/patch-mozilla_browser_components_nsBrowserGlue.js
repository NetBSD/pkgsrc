$NetBSD: patch-mozilla_browser_components_nsBrowserGlue.js,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/browser/components/nsBrowserGlue.js.orig	2017-07-07 05:35:43.000000000 +0000
+++ mozilla/browser/components/nsBrowserGlue.js
@@ -931,7 +931,9 @@ BrowserGlue.prototype = {
     }
     if (SCALING_PROBE_NAME) {
       let scaling = aWindow.devicePixelRatio * 100;
-      Services.telemetry.getHistogramById(SCALING_PROBE_NAME).add(scaling);
+      try {
+        Services.telemetry.getHistogramById(SCALING_PROBE_NAME).add(scaling);
+      } catch (ex) {}
     }
   },
 
