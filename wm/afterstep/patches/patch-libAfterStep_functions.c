$NetBSD: patch-libAfterStep_functions.c,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterStep/functions.c.orig	2012-05-04 14:34:35.000000000 +0000
+++ libAfterStep/functions.c
@@ -314,7 +314,7 @@ dup_func_data (FunctionData * dst, Funct
     }
 }
 
-inline FunctionData *
+FunctionData *
 create_named_function( int func, char *name)
 {
     FunctionData *fdata = safecalloc( 1, sizeof(FunctionData) );
