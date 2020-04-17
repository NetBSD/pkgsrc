$NetBSD: patch-eworkpanel_aboutdialog.cpp,v 1.1 2020/04/17 13:31:46 joerg Exp $

--- eworkpanel/aboutdialog.cpp.orig	2020-04-17 12:31:57.407732601 +0000
+++ eworkpanel/aboutdialog.cpp
@@ -14,7 +14,7 @@ void AboutDialog(Fl_Widget*, void*) {
    {Fl_Window* o = mAboutDialogWindow = new Fl_Window(355, 305, _("About Equinox Desktop Environment"));
     w = o;
     o->shortcut(0xff1b);
-     {Fl_Box* o = new Fl_Box(5, 25, 345, 35, _("Equinox Desktop Environment "PACKAGE_VERSION));
+     {Fl_Box* o = new Fl_Box(5, 25, 345, 35, _("Equinox Desktop Environment " PACKAGE_VERSION));
       o->label_font(fl_fonts+1);
       o->color((Fl_Color)56);
       o->label_color((Fl_Color)32);
