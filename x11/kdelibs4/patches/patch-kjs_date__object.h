$NetBSD: patch-kjs_date__object.h,v 1.1 2018/01/31 11:33:22 jperkin Exp $

Remove bogus forward declaration.

--- kjs/date_object.h.orig	2017-11-05 01:51:22.000000000 +0000
+++ kjs/date_object.h
@@ -24,8 +24,6 @@
 #include "function.h"
 #include "JSWrapperObject.h"
 
-struct tm;
-
 namespace KJS {
 
     class FunctionPrototype;
