$NetBSD: patch-dw_fltkui.cc,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- dw/fltkui.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ dw/fltkui.cc
@@ -365,14 +365,14 @@ int CustChoice::handle(int e)
       if (k == FL_Enter || k == FL_Down) {
          return Fl_Choice::handle(FL_PUSH); // activate menu
 
-      } else if (isalnum(k)) { // try key as shortcut to menuitem
+      } else if (dIsalnum(k)) { // try key as shortcut to menuitem
          int t = value()+1 >= size() ? 0 : value()+1;
          while (t != value()) {
              const Fl_Menu_Item *mi = &(menu()[t]);
              if (mi->submenu()) // submenu?
                 ;
              else if (mi->label() && mi->active()) { // menu item?
-                if (k == tolower(mi->label()[0])) {
+                if (k == dTolower(mi->label()[0])) {
                    value(mi);
                    return 1; // Let FLTK know we used this key
                 }
