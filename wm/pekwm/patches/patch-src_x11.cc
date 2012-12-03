$NetBSD: patch-src_x11.cc,v 1.1 2012/12/03 21:46:48 gls Exp $

#pragma GCC diagnostic inside function is a GCC 4.6+ fetaure.
https://www.pekwm.org/projects/pekwm/tasks/318

--- src/x11.cc.orig	2012-11-17 18:42:40.000000000 +0000
+++ src/x11.cc
@@ -993,6 +993,8 @@ X11::getKeycodeFromMask(uint mask)
 /**
  * Wrapper for XKeycodeToKeysym and XkbKeycodeToKeysym depending on which one is available.
  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 KeySym
 X11::getKeysymFromKeycode(KeyCode keycode)
 {
@@ -1002,11 +1004,9 @@ X11::getKeysymFromKeycode(KeyCode keycod
     else
 #endif
 
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         return XKeycodeToKeysym(_dpy, keycode, 0);
-#pragma GCC diagnostic pop
 }
+#pragma GCC diagnostic pop
 
 Display *X11::_dpy;
 bool X11::_honour_randr = false;
