$NetBSD: patch-efltk_Fl__Window.h,v 1.1 2011/05/21 08:18:16 obache Exp $

--- efltk/Fl_Window.h.orig	2003-05-14 21:07:55.000000000 +0000
+++ efltk/Fl_Window.h
@@ -27,6 +27,8 @@
 // value for x,y to indicate window system places window
 #define FL_USEDEFAULT ((int)0x80000000) // same as Win32 value
 
+class Fl_X;
+
 /** Fl_Window */
 class FL_API Fl_Window : public Fl_Group {
 public:
