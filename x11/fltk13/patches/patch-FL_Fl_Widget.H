$NetBSD: patch-FL_Fl_Widget.H,v 1.2 2015/07/21 21:36:41 markd Exp $

Fl_X tries to access protected members of Fl_Widget.

and part of tigervnc.patch from archlinux package. 

--- FL/Fl_Widget.H.orig	2014-09-08 08:55:49.000000000 +0000
+++ FL/Fl_Widget.H
@@ -99,6 +99,7 @@ struct FL_EXPORT Fl_Label {
  */
 class FL_EXPORT Fl_Widget {
   friend class Fl_Group;
+  friend class Fl_X;
 
   Fl_Group* parent_;
   Fl_Callback* callback_;
@@ -172,6 +173,7 @@ protected:
         COPIED_TOOLTIP  = 1<<17,  ///< the widget tooltip is internally copied, its destruction is handled by the widget
         FULLSCREEN      = 1<<18,  ///< a fullscreen window (Fl_Window)
         MAC_USE_ACCENTS_MENU = 1<<19, ///< On the Mac OS platform, pressing and holding a key on the keyboard opens an accented-character menu window (Fl_Input_, Fl_Text_Editor)
+       SIMPLE_KEYBOARD = 1<<20,  ///< the widget wants simple, consistent keypresses and not advanced input (like character composition and CJK input)
         // (space for more flags)
         USERFLAG3       = 1<<29,  ///< reserved for 3rd party extensions
         USERFLAG2       = 1<<30,  ///< reserved for 3rd party extensions
@@ -789,6 +791,35 @@ public:
    */
   void set_active() {flags_ &= ~INACTIVE;}
 
+  /** 
+      Returns if the widget sees a simplified keyboard model or not.
+
+      Normally widgets get a full-featured keyboard model that is geared
+      towards text input. This includes support for compose sequences and
+      advanced input methods, commonly used for asian writing system. This
+      system however has downsides in that extra graphic can be presented
+      to the user and that a physical key press doesn't correspond directly
+      to a FLTK event.
+
+      Widgets that need a direct correspondence between actual key events
+      and those seen by the widget can swith to the simplified keyboard
+      model.
+
+     \retval 0 if the widget uses the normal keyboard model
+     \see set_changed(), clear_changed()
+   */
+  unsigned int simple_keyboard() const {return flags_&SIMPLE_KEYBOARD;}
+
+  /** Marks a widget to use the simple keyboard model.
+      \see changed(), clear_changed()
+   */
+  void set_simple_keyboard() {flags_ |= SIMPLE_KEYBOARD;}
+
+  /** Marks a widget to use the normal keyboard model.
+      \see changed(), set_changed()
+   */
+  void set_normal_keyboard() {flags_ &= ~SIMPLE_KEYBOARD;}
+
   /** Gives the widget the keyboard focus.
       Tries to make this widget be the Fl::focus() widget, by first sending 
       it an FL_FOCUS event, and if it returns non-zero, setting 
