$NetBSD: patch-fluid_FluidType.h,v 1.1 2013/07/13 19:44:54 joerg Exp $

--- fluid/FluidType.h.orig	2013-07-13 18:18:38.000000000 +0000
+++ fluid/FluidType.h
@@ -42,7 +42,7 @@
 class FLUID_API FluidType {
 
   friend class Widget_Browser;
-  friend fltk::Widget *make_type_browser(int,int,int,int,const char *l=0);
+  friend fltk::Widget *make_type_browser(int,int,int,int,const char *l);
   friend class WindowType;
   virtual void setlabel(const char *); // virtual part of label(char*)
 
