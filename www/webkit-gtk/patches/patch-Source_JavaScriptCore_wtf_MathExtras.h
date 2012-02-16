$NetBSD: patch-Source_JavaScriptCore_wtf_MathExtras.h,v 1.1 2012/02/16 20:47:34 hans Exp $

--- Source/JavaScriptCore/wtf/MathExtras.h.orig	2011-09-26 22:54:57.000000000 +0200
+++ Source/JavaScriptCore/wtf/MathExtras.h	2011-12-08 15:00:06.791014713 +0100
@@ -259,7 +259,7 @@ inline bool isWithinIntRange(float x)
     return x > static_cast<float>(std::numeric_limits<int>::min()) && x < static_cast<float>(std::numeric_limits<int>::max());
 }
 
-#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !OS(SOLARIS) && !OS(SYMBIAN)
+#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !(OS(SOLARIS) && COMPILER(GCC) && (GCC_VERSION < 40600)) && !OS(SYMBIAN)
 using std::isfinite;
 using std::isinf;
 using std::isnan;
