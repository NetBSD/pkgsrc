$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_MathExtras.h,v 1.1 2024/03/14 07:59:55 adam Exp $

Fix build on Darwin: ceil(-0.1) returns -0.0;

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/MathExtras.h.orig	2024-03-11 09:37:27.641077856 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/MathExtras.h
@@ -68,7 +68,7 @@ const double piOverFourDouble = M_PI_4;
 const float piOverFourFloat = static_cast<float>(M_PI_4);
 #endif
 
-#if OS(DARWIN)
+#if 0
 
 // Work around a bug in the Mac OS X libc where ceil(-0.1) return +0.
 inline double wtf_ceil(double x) { return copysign(ceil(x), x); }
