$NetBSD: patch-ext_gtk2_rbgtktreeviewcolumn.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/gtk2/rbgtktreeviewcolumn.c.orig	2018-04-29 15:18:34.000000000 +0000
+++ ext/gtk2/rbgtktreeviewcolumn.c
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2011  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2011-2018 Ruby-GNOME2 Project Team
  *  Copyright (C) 2002-2004 Masao Mutoh
  *
  *  This library is free software; you can redistribute it and/or
@@ -83,7 +83,11 @@ rg_pack_end(VALUE self, VALUE cell, VALU
 static VALUE
 rg_clear(VALUE self)
 {
-    G_CHILD_REMOVE_ALL(self);
+    static VALUE rb_cGtkCellRenderer = Qnil;
+    if (NIL_P(rb_cGtkCellRenderer)) {
+        rb_cGtkCellRenderer = GTYPE2CLASS(GTK_TYPE_CELL_RENDERER);
+    }
+    rbgobj_object_remove_relatives(self, rb_cGtkCellRenderer);
     gtk_tree_view_column_clear(_SELF(self));
     return self;
 }
