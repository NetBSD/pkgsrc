$NetBSD: patch-js_dbusServices_screencast_screencastService.js,v 1.1 2024/05/09 20:27:46 wiz Exp $

Fix compatibility with glib2 2.80.1.
https://gitlab.gnome.org/GNOME/gnome-shell/-/merge_requests/3303

--- js/dbusServices/screencast/screencastService.js.orig	2021-06-10 11:33:01.564930400 +0000
+++ js/dbusServices/screencast/screencastService.js
@@ -161,7 +161,7 @@ var Recorder = class {
             });
 
         this._streamProxy = new ScreenCastStreamProxy(Gio.DBus.session,
-            'org.gnome.ScreenCast.Stream',
+            'org.gnome.Mutter.ScreenCast',
             streamPath);
 
         this._streamProxy.connectSignal('PipeWireStreamAdded',
