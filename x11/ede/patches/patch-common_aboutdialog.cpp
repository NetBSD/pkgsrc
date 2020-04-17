$NetBSD: patch-common_aboutdialog.cpp,v 1.1 2020/04/17 13:31:46 joerg Exp $

--- common/aboutdialog.cpp.orig	2020-04-17 12:09:09.329472450 +0000
+++ common/aboutdialog.cpp
@@ -38,7 +38,7 @@ AboutDialog::AboutDialog(const char *pro
 		}
 		 {Fl_Box* o = new Fl_Box(5, 49, 265, 20, _("Part of Equinox Desktop Environment"));
 			o->align(FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
-			o->label(o->label() + Fl_String(" "PACKAGE_VERSION));
+			o->label(o->label() + Fl_String(" " PACKAGE_VERSION));
 		}
 		 {Fl_Box* o = new Fl_Box(5, 74, 265, 20, _("Copyright (c) 2000-2005 EDE Authors"));
 			o->align(FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
