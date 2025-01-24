$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.4 2025/01/24 11:54:37 wiz Exp $

Fix SunOS build.

--- Source/WTF/wtf/MathExtras.h.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -75,7 +75,7 @@ const double sqrtOfTwoDouble = M_SQRT2;
 const float sqrtOfTwoFloat = static_cast<float>(M_SQRT2);
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
