$NetBSD: patch-fluid_Fl__Type.h,v 1.1 2013/07/13 19:44:54 joerg Exp $

Friends may not declare default arguments with being a definition.

--- fluid/Fl_Type.h.orig	2013-07-12 17:49:55.000000000 +0000
+++ fluid/Fl_Type.h
@@ -36,7 +36,7 @@ void set_modflag(int mf);
 class Fl_Type {
 
   friend class Widget_Browser;
-  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l=0);
+  friend Fl_Widget *make_type_browser(int,int,int,int,const char *l);
   friend class Fl_Window_Type;
   virtual void setlabel(const char *); // virtual part of label(char*)
 
