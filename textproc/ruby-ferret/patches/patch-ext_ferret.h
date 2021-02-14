$NetBSD: patch-ext_ferret.h,v 1.1 2021/02/14 15:06:43 taca Exp $

Use modern API.

--- ext/ferret.h.orig	2021-01-11 06:15:38.540000961 +0000
+++ ext/ferret.h
@@ -72,7 +72,7 @@ extern char *rs2s(VALUE rstr);
 extern char *rstrdup(VALUE rstr);
 extern Symbol rintern(VALUE rstr);
 #define Frt_Make_Struct(klass)\
-  rb_data_object_alloc(klass,NULL,(RUBY_DATA_FUNC)NULL,(RUBY_DATA_FUNC)NULL)
+  rb_data_object_wrap(klass,NULL,(RUBY_DATA_FUNC)NULL,(RUBY_DATA_FUNC)NULL)
 
 #define Frt_Wrap_Struct(self,mmark,mfree,mdata)\
   do {\
