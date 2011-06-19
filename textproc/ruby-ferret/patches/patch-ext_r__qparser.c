$NetBSD: patch-ext_r__qparser.c,v 1.1 2011/06/19 16:01:52 taca Exp $

* Switch to modern Ruby's API: http://cvs.pld-linux.org/

--- ext/r_qparser.c.orig	2011-06-10 06:23:08.000000000 +0000
+++ ext/r_qparser.c
@@ -53,8 +53,8 @@ frt_get_fields(VALUE rfields)
     fields = hs_new_str(&free);
     if (TYPE(rfields) == T_ARRAY) {
         int i;
-        for (i = 0; i < RARRAY(rfields)->len; i++) {
-            rval = rb_obj_as_string(RARRAY(rfields)->ptr[i]);
+        for (i = 0; i < RARRAY_LEN(rfields); i++) {
+            rval = rb_obj_as_string(RARRAY_PTR(rfields)[i]);
             hs_add(fields, nstrdup(rval));
         }
     } else {
