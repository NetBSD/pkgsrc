$NetBSD: patch-fluid_Fl__Type.h,v 1.1 2013/07/13 19:44:54 joerg Exp $

--- fluid/Fl_Type.h.orig	2008-01-04 21:45:49.000000000 +0000
+++ fluid/Fl_Type.h
@@ -44,7 +44,7 @@ void set_modflag(int mf);
 class Fl_Type {
 
   friend class Widget_Browser;
-  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l=0);
+  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l);
   friend class Fl_Window_Type;
   virtual void setlabel(const char *); // virtual part of label(char*)
 
