$NetBSD: patch-src_Fl.cxx,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl.cxx.orig	2014-10-08 12:47:20.000000000 +0000
+++ src/Fl.cxx
@@ -70,6 +70,8 @@ void fl_cleanup_dc_list(void);
 extern double fl_mac_flush_and_wait(double time_to_wait);
 #endif // WIN32
 
+extern void fl_update_focus(void);
+
 //
 // Globals...
 //
@@ -982,6 +984,8 @@ void Fl::focus(Fl_Widget *o) {
       fl_oldfocus = p;
     }
     e_number = old_event;
+    // let the platform code do what it needs
+    fl_update_focus();
   }
 }
 
