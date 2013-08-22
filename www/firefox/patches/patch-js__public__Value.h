$NetBSD: patch-js__public__Value.h,v 1.1 2013/08/22 14:23:35 martin Exp $

Fix jsvalue_layout for big endian 64 bit case.
Fixed the same way upstream already.


--- js/public/Value.h.orig	2013-08-14 15:49:29.000000000 +0200
+++ js/public/Value.h	2013-08-22 14:55:04.000000000 +0200
@@ -321,7 +321,6 @@ typedef union jsval_layout
             int32_t        i32;
             uint32_t       u32;
             JSWhyMagic     why;
-            uintptr_t      word;
         } payload;
     } s;
     double asDouble;
