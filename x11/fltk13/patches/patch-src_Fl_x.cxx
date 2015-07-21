$NetBSD: patch-src_Fl_x.cxx,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package. 

--- src/Fl_x.cxx.orig	2014-10-29 20:25:46.000000000 +0000
+++ src/Fl_x.cxx
@@ -666,6 +666,30 @@ void Fl::disable_im() {
   fl_xim_deactivate();
 }
 
+extern Fl_Window *fl_xfocus;
+
+void fl_update_focus(void)
+{
+  Fl_Widget *focus;
+
+  focus = Fl::grab();
+  if (!focus)
+    focus = Fl::focus();
+  if (!focus)
+    return;
+
+  if (focus->simple_keyboard()) {
+    fl_xim_deactivate();
+  } else {
+    // fl_xfocus should always be set if something has focus, but let's
+    // play it safe
+    if (!fl_xfocus || !fl_xid(fl_xfocus))
+      return;
+
+    fl_xim_activate(fl_xid(fl_xfocus));
+  }
+}
+
 void fl_open_display() {
   if (fl_display) return;
 
@@ -2211,6 +2235,7 @@ int Fl_X::ewmh_supported() {
   static int result = -1;
 
   if (result == -1) {
+    fl_open_display();
     result = 0;
     unsigned long nitems;
     unsigned long *words = 0;
