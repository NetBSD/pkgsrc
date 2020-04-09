$NetBSD: patch-browser_components_BrowserGlue.jsm,v 1.1 2020/04/09 14:01:26 ryoon Exp $

* Silence Service.profiler errors on Tier3 after bug 1613390

--- browser/components/BrowserGlue.jsm.orig	2020-04-03 19:34:29.000000000 +0000
+++ browser/components/BrowserGlue.jsm
@@ -2289,7 +2289,9 @@ BrowserGlue.prototype = {
       ChromeUtils.idleDispatch(
         () => {
           if (!Services.startup.shuttingDown) {
-            Services.profiler.AddMarker("startupIdleTask");
+            if (Services.profiler) {
+              Services.profiler.AddMarker("startupIdleTask");
+            }
             try {
               task.task();
             } catch (ex) {
@@ -2360,7 +2362,9 @@ BrowserGlue.prototype = {
     for (let task of idleTasks) {
       ChromeUtils.idleDispatch(() => {
         if (!Services.startup.shuttingDown) {
-          Services.profiler.AddMarker("startupLateIdleTask");
+          if (Services.profiler) {
+            Services.profiler.AddMarker("startupLateIdleTask");
+          }
           try {
             task();
           } catch (ex) {
