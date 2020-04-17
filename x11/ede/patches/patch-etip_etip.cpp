$NetBSD: patch-etip_etip.cpp,v 1.1 2020/04/17 13:31:46 joerg Exp $

--- etip/etip.cpp.orig	2020-04-17 12:19:01.541960966 +0000
+++ etip/etip.cpp
@@ -837,7 +837,7 @@ int main (int argc, char **argv) {
         o->label(tips[activeTip]);
         o->window()->redraw();
       }
-       {Fl_Box* o = new Fl_Box(0, 0, 310, 45, _("Welcome to Equinox Desktop Environment version "PACKAGE_VERSION));
+       {Fl_Box* o = new Fl_Box(0, 0, 310, 45, _("Welcome to Equinox Desktop Environment version " PACKAGE_VERSION));
         o->box(FL_FLAT_BOX);
         o->color((Fl_Color)0x8ef400); 
         o->label_color((Fl_Color)32);
