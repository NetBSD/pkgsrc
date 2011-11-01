$NetBSD: patch-src_3rdparty_webkit_JavaScriptCore_wtf_MathExtras.h,v 1.3 2011/11/01 15:52:23 hans Exp $

--- src/3rdparty/webkit/JavaScriptCore/wtf/MathExtras.h.orig	2011-08-23 12:02:27.000000000 +0000
+++ src/3rdparty/webkit/JavaScriptCore/wtf/MathExtras.h
@@ -190,7 +190,7 @@ inline float deg2turn(float d) { return 
 inline float rad2grad(float r) { return r * 200.0f / piFloat; }
 inline float grad2rad(float g) { return g * piFloat / 200.0f; }
 
-#if !COMPILER(MSVC) && !OS(ANDROID) && !OS(SYMBIAN)
+#if !COMPILER(MSVC) && !OS(ANDROID) && !OS(SYMBIAN) && !(OS(SOLARIS) && COMPILER(GCC) && (GCC_VERSION < 40600))
 using std::isfinite;
 using std::isinf;
 using std::isnan;
