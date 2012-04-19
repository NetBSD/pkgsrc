$NetBSD: patch-FL_Fl_Widget.H,v 1.1 2012/04/19 21:09:29 joerg Exp $

Fl_X tries to access protected members of Fl_Widget.

--- FL/Fl_Widget.H.orig	2012-04-19 16:12:57.000000000 +0000
+++ FL/Fl_Widget.H
@@ -108,6 +108,7 @@ struct FL_EXPORT Fl_Label {
  */
 class FL_EXPORT Fl_Widget {
   friend class Fl_Group;
+  friend class Fl_X;
 
   Fl_Group* parent_;
   Fl_Callback* callback_;
