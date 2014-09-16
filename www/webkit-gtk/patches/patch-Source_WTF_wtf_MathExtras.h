$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.3 2014/09/16 11:56:13 jperkin Exp $

Avoid broken section for SunOS/gcc.

--- Source/WTF/wtf/MathExtras.h.orig	2014-08-25 12:50:32.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -76,7 +76,7 @@ inline double wtf_ceil(double x) { retur
 
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
