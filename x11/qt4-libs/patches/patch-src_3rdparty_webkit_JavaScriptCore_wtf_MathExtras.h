$NetBSD: patch-src_3rdparty_webkit_JavaScriptCore_wtf_MathExtras.h,v 1.1 2011/09/14 17:58:32 hans Exp $

--- src/3rdparty/webkit/JavaScriptCore/wtf/MathExtras.h.orig	2010-11-06 02:55:19.000000000 +0100
+++ src/3rdparty/webkit/JavaScriptCore/wtf/MathExtras.h	2011-01-16 11:57:37.742721037 +0100
@@ -190,7 +190,7 @@ inline float deg2turn(float d) { return 
 inline float rad2grad(float r) { return r * 200.0f / piFloat; }
 inline float grad2rad(float g) { return g * piFloat / 200.0f; }
 
-#if !COMPILER(MSVC) && !COMPILER(RVCT) && !OS(ANDROID) && !COMPILER(WINSCW)
+#if !COMPILER(MSVC) && !COMPILER(WINSCW) && !(COMPILER(RVCT) && (OS(SYMBIAN) || PLATFORM(BREWMP))) && !OS(SOLARIS)
 using std::isfinite;
 using std::isinf;
 using std::isnan;
