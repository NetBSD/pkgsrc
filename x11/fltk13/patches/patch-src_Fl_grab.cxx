$NetBSD: patch-src_Fl_grab.cxx,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl_grab.cxx.orig	2012-03-23 16:47:53.000000000 +0000
+++ src/Fl_grab.cxx
@@ -29,6 +29,7 @@
 // override_redirect, it does similar things on WIN32.
 
 extern void fl_fix_focus(); // in Fl.cxx
+extern void fl_update_focus(void);
 
 #ifdef WIN32
 // We have to keep track of whether we have captured the mouse, since
@@ -80,6 +81,7 @@ void Fl::grab(Fl_Window* win) {
 #endif
     }
     grab_ = win;
+    fl_update_focus();
   } else {
     if (grab_) {
 #ifdef WIN32
@@ -98,6 +100,7 @@ void Fl::grab(Fl_Window* win) {
       XFlush(fl_display);
 #endif
       grab_ = 0;
+      fl_update_focus();
       fl_fix_focus();
     }
   }
