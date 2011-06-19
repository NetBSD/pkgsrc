$NetBSD: patch-ext_ferret.c,v 1.1 2011/06/19 16:01:52 taca Exp $

* Switch to modern Ruby's API: http://cvs.pld-linux.org/

--- ext/ferret.c.orig	2011-06-10 06:23:08.000000000 +0000
+++ ext/ferret.c
@@ -162,14 +162,14 @@ void *frt_rb_data_ptr(VALUE val)
 char *
 rs2s(VALUE rstr)
 {
-    return (char *)(RSTRING(rstr)->ptr ? RSTRING(rstr)->ptr : EMPTY_STRING);
+    return (char *)(RSTRING_PTR(rstr) ? RSTRING_PTR(rstr) : EMPTY_STRING);
 }
 
 char *
 nstrdup(VALUE rstr)
 {
     char *old = rs2s(rstr);
-    int len = RSTRING(rstr)->len;
+    int len = RSTRING_LEN(rstr);
     char *new = ALLOC_N(char, len + 1);
     memcpy(new, old, len + 1);
     return new;
@@ -295,7 +295,7 @@ static VALUE frt_term_to_s(VALUE self)
     char *field = StringValuePtr(rfield);
     char *text = StringValuePtr(rtext);
     char *term_str = ALLOC_N(char,
-                             5 + RSTRING(rfield)->len + RSTRING(rtext)->len);
+                             5 + RSTRING_LEN(rfield) + RSTRING_LEN(rtext));
     sprintf(term_str, "%s:%s", field, text);
     rstr = rb_str_new2(term_str);
     free(term_str);
