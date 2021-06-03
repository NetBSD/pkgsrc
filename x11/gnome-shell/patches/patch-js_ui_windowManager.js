$NetBSD: patch-js_ui_windowManager.js,v 1.1 2021/06/03 15:11:05 cirnatdan Exp $

Remove systemd code

--- js/ui/windowManager.js.orig	2021-03-20 12:17:01.442522300 +0000
+++ js/ui/windowManager.js
@@ -974,8 +974,8 @@ var WindowManager = class {
 
     async _startX11Services(task, cancellable) {
         try {
-            await Shell.util_start_systemd_unit(
-                'gnome-session-x11-services-ready.target', 'fail', cancellable);
+            //await Shell.util_start_systemd_unit(
+            //    'gnome-session-x11-services-ready.target', 'fail', cancellable);
         } catch (e) {
             // Ignore NOT_SUPPORTED error, which indicates we are not systemd
             // managed and gnome-session will have taken care of everything
@@ -990,8 +990,8 @@ var WindowManager = class {
 
     async _stopX11Services(cancellable) {
         try {
-            await Shell.util_stop_systemd_unit(
-                'gnome-session-x11-services.target', 'fail', cancellable);
+            //await Shell.util_stop_systemd_unit(
+            //    'gnome-session-x11-services.target', 'fail', cancellable);
         } catch (e) {
             // Ignore NOT_SUPPORTED error, which indicates we are not systemd
             // managed and gnome-session will have taken care of everything
