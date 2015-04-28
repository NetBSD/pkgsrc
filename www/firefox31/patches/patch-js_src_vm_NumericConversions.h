$NetBSD: patch-js_src_vm_NumericConversions.h,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/vm/NumericConversions.h.orig	2015-04-10 16:14:14.000000000 +0000
+++ js/src/vm/NumericConversions.h
@@ -130,7 +130,7 @@ ToIntWidth(double d)
 inline int32_t
 ToInt32(double d)
 {
-#if defined (__arm__) && defined (__GNUC__)
+#if defined (__arm__) && defined (__GNUC__) && !defined(__clang__)
     int32_t i;
     uint32_t    tmp0;
     uint32_t    tmp1;
