$NetBSD: patch-kjs_date_object.h,v 1.1 2018/02/08 10:50:44 mrg Exp $

Replace bogus forward declaration with <ctime> include.

--- kjs/date_object.h.orig	2017-11-05 01:51:22.000000000 +0000
+++ kjs/date_object.h
@@ -24,8 +24,8 @@
 #include "function.h"
 #include "JSWrapperObject.h"
 
-struct tm;
+#include <ctime>
 
 namespace KJS {
 
     class FunctionPrototype;
