$NetBSD: patch-src_Fl_grab.cxx,v 1.2 2016/01/26 08:47:28 dbj Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl_grab.cxx.orig	2012-03-23 16:47:53.000000000 +0000
+++ src/Fl_grab.cxx
@@ -29,6 +29,9 @@
 // override_redirect, it does similar things on WIN32.
 
 extern void fl_fix_focus(); // in Fl.cxx
+#if !defined(WIN32) && !defined(__APPLE__)
+extern void fl_update_focus(void);
+#endif
 
 #ifdef WIN32
 // We have to keep track of whether we have captured the mouse, since
@@ -80,6 +83,9 @@ void Fl::grab(Fl_Window* win) {
 #endif
     }
     grab_ = win;
+#if !defined(WIN32) && !defined(__APPLE__)
+    fl_update_focus();
+#endif
   } else {
     if (grab_) {
 #ifdef WIN32
@@ -98,6 +104,9 @@ void Fl::grab(Fl_Window* win) {
       XFlush(fl_display);
 #endif
       grab_ = 0;
+#if !defined(WIN32) && !defined(__APPLE__)
+      fl_update_focus();
+#endif
       fl_fix_focus();
     }
   }
