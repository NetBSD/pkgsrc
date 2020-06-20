$NetBSD: patch-bindings_vala_app.vala,v 1.1 2020/06/20 16:00:07 nia Exp $

NetBSD build fix.

--- bindings/vala/app.vala.orig	2020-05-13 09:51:07.000000000 +0000
+++ bindings/vala/app.vala
@@ -492,7 +492,7 @@ class Window : Gtk.ApplicationWindow
 
     switch (pid) {
     case -1: /* error */
-      printerr("Error forking: %m");
+      printerr("Error forking: %s", strerror(errno));
       break;
     case 0: /* child */ {
       pty.child_setup();
