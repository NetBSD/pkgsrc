$NetBSD: patch-ext_nokogumbo_nokogumbo.c,v 1.1 2023/01/30 13:58:52 taca Exp $

* Stop using rb_cData for Ruby 3.2.

--- ext/nokogumbo/nokogumbo.c.orig	2023-01-30 13:55:48.687307066 +0000
+++ ext/nokogumbo/nokogumbo.c
@@ -489,7 +489,7 @@ static void parse_args_mark(void *parse_
 // Wrap a ParseArgs pointer. The underlying ParseArgs must outlive the
 // wrapper.
 static VALUE wrap_parse_args(ParseArgs *args) {
-  return Data_Wrap_Struct(rb_cData, parse_args_mark, RUBY_NEVER_FREE, args);
+  return Data_Wrap_Struct(rb_cObject, parse_args_mark, RUBY_NEVER_FREE, args);
 }
 
 // Returnsd the underlying ParseArgs wrapped by wrap_parse_args.
