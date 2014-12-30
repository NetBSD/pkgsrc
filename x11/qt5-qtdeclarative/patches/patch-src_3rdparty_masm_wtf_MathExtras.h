$NetBSD: patch-src_3rdparty_masm_wtf_MathExtras.h,v 1.1 2014/12/30 17:23:46 adam Exp $

Skip bad section for SunOS, at least newer releases.

--- src/3rdparty/masm/wtf/MathExtras.h.orig	2014-02-01 20:38:03.000000000 +0000
+++ src/3rdparty/masm/wtf/MathExtras.h
@@ -88,7 +88,7 @@ inline double wtf_ceil(double x) { retur
 
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
