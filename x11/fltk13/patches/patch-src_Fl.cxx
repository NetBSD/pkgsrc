$NetBSD: patch-src_Fl.cxx,v 1.2 2016/01/26 08:47:28 dbj Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl.cxx.orig	2014-10-08 12:47:20.000000000 +0000
+++ src/Fl.cxx
@@ -70,6 +70,10 @@ void fl_cleanup_dc_list(void);
 extern double fl_mac_flush_and_wait(double time_to_wait);
 #endif // WIN32
 
+#if !defined(WIN32) && !defined(__APPLE__)
+extern void fl_update_focus(void);
+#endif
+
 //
 // Globals...
 //
@@ -982,6 +986,10 @@ void Fl::focus(Fl_Widget *o) {
       fl_oldfocus = p;
     }
     e_number = old_event;
+#if !defined(WIN32) && !defined(__APPLE__)
+    // let the platform code do what it needs
+    fl_update_focus();
+#endif
   }
 }
 
