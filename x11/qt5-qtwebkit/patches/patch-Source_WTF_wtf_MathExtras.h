$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.2 2018/01/17 19:37:33 markd Exp $

Fix SunOS build.

--- Source/WTF/wtf/MathExtras.h.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -75,7 +75,7 @@ const double sqrtOfTwoDouble = M_SQRT2;
 const float sqrtOfTwoFloat = static_cast<float>(M_SQRT2);
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
