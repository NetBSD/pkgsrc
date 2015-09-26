$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.5 2015/09/26 10:16:38 leot Exp $

Avoid broken section for SunOS/gcc.

--- Source/WTF/wtf/MathExtras.h.orig	2015-09-14 07:08:10.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -75,7 +75,7 @@ const double sqrtOfTwoDouble = M_SQRT2;
 const float sqrtOfTwoFloat = static_cast<float>(M_SQRT2);
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
