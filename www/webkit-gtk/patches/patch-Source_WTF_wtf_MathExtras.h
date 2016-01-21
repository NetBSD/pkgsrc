$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.6 2016/01/21 13:42:33 leot Exp $

Avoid broken section for SunOS/gcc.

--- Source/WTF/wtf/MathExtras.h.orig	2016-01-20 12:13:00.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -75,7 +75,7 @@ const double sqrtOfTwoDouble = M_SQRT2;
 const float sqrtOfTwoFloat = static_cast<float>(M_SQRT2);
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
