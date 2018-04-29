$NetBSD: patch-ext_gtk2_rbgtktreestore.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/gtk2/rbgtktreestore.c.orig	2018-04-29 15:18:34.000000000 +0000
+++ ext/gtk2/rbgtktreestore.c
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2011-2012  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2011-2018 Ruby-GNOME2 Project Team
  *  Copyright (C) 2002-2006 Masao Mutoh
  *
  *  This library is free software; you can redistribute it and/or
@@ -273,7 +273,11 @@ rg_iter_depth(VALUE self, VALUE iter)
 static VALUE
 rg_clear(VALUE self)
 {
-    G_CHILD_REMOVE_ALL(self);
+    static VALUE rb_cGtkTreeIter = Qnil;
+    if (NIL_P(rb_cGtkTreeIter)) {
+        rb_cGtkTreeIter = GTYPE2CLASS(GTK_TYPE_TREE_ITER);
+    }
+    rbgobj_object_remove_relatives(self, rb_cGtkTreeIter);
     gtk_tree_store_clear(_SELF(self));
     return self;
 }
