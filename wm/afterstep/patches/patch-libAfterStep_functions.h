$NetBSD: patch-libAfterStep_functions.h,v 1.2 2016/05/01 19:30:58 dholland Exp $

Patch up gcc inline mess.

--- libAfterStep/functions.h.orig	2012-05-04 14:34:21.000000000 +0000
+++ libAfterStep/functions.h
@@ -250,7 +250,7 @@ FunctionData *String2Func ( const char *
 void init_func_data (FunctionData * data);
 void copy_func_data (FunctionData * dst, FunctionData * src);
 void dup_func_data (FunctionData * dst, FunctionData * src);
-inline FunctionData *create_named_function( int func, char *name);
+FunctionData *create_named_function( int func, char *name);
 void set_func_val (FunctionData * data, int arg, int value);
 int free_func_data (FunctionData * data);
 void destroy_func_data( FunctionData **pdata );
