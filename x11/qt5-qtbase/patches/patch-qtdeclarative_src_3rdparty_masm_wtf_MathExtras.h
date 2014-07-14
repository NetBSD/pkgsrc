$NetBSD: patch-qtdeclarative_src_3rdparty_masm_wtf_MathExtras.h,v 1.1 2014/07/14 16:32:14 jperkin Exp $

Skip bad section for SunOS, at least newer releases.

--- qtdeclarative/src/3rdparty/masm/wtf/MathExtras.h.orig	2014-02-01 20:38:03.000000000 +0000
+++ qtdeclarative/src/3rdparty/masm/wtf/MathExtras.h
@@ -88,7 +88,7 @@ inline double wtf_ceil(double x) { retur
 
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
