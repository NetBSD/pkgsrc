$NetBSD: patch-core_browser.vala,v 1.1 2020/06/16 13:54:24 nia Exp $

Resolve some issues typing in the URL bar.

https://github.com/midori-browser/core/issues/364
https://github.com/midori-browser/core/pull/365

--- core/browser.vala.orig	2019-07-29 21:59:54.000000000 +0000
+++ core/browser.vala
@@ -121,13 +121,13 @@ namespace Midori {
                 application.set_accels_for_action ("win.tab-reopen", { "<Primary><Shift>t" });
                 application.set_accels_for_action ("win.fullscreen", { "F11" });
                 application.set_accels_for_action ("win.show-downloads", { "<Primary><Shift>j" });
-                application.set_accels_for_action ("win.find", { "<Primary>f", "slash" });
+                application.set_accels_for_action ("win.find", { "<Primary>f" });
                 application.set_accels_for_action ("win.view-source", { "<Primary>u", "<Primary><Alt>u" });
                 application.set_accels_for_action ("win.print", { "<Primary>p" });
                 application.set_accels_for_action ("win.caret-browsing", { "F7" });
                 application.set_accels_for_action ("win.show-inspector", { "<Primary><Shift>i" });
                 application.set_accels_for_action ("win.goto", { "<Primary>l", "F7" });
-                application.set_accels_for_action ("win.go-back", { "<Alt>Left", "BackSpace", "Back" });
+                application.set_accels_for_action ("win.go-back", { "<Alt>Left" });
                 application.set_accels_for_action ("win.go-forward", { "<Alt>Right", "<Shift>BackSpace" });
                 application.set_accels_for_action ("win.tab-reload", { "<Primary>r", "F5" });
                 application.set_accels_for_action ("win.tab-stop-loading", { "Escape" });
@@ -136,7 +136,7 @@ namespace Midori {
                 application.set_accels_for_action ("win.tab-next", { "<Primary>Tab" });
                 application.set_accels_for_action ("win.clear-private-data", { "<Primary><Shift>Delete" });
                 application.set_accels_for_action ("win.preferences", { "<Primary><Alt>p" });
-                application.set_accels_for_action ("win.show-help-overlay", { "<Primary>F1", "<Shift>question" });
+                application.set_accels_for_action ("win.show-help-overlay", { "<Primary>F1" });
 
                 for (var i = 0; i < 10; i++) {
                     application.set_accels_for_action ("win.tab-by-index(%d)".printf(i),
