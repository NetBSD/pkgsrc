$NetBSD: patch-kjs_date_object.h,v 1.2 2020/03/24 20:34:31 joerg Exp $

Replace bogus forward declaration with <ctime> include.

--- kjs/date_object.h.orig	2017-11-05 01:51:22.000000000 +0000
+++ kjs/date_object.h
@@ -24,7 +24,7 @@
 #include "function.h"
 #include "JSWrapperObject.h"
 
-struct tm;
+#include <ctime>
 
 namespace KJS {
 
