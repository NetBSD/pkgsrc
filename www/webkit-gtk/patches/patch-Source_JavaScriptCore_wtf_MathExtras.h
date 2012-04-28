$NetBSD: patch-Source_JavaScriptCore_wtf_MathExtras.h,v 1.2 2012/04/28 14:12:16 drochner Exp $

--- Source/JavaScriptCore/wtf/MathExtras.h.orig	2012-04-24 01:38:21.000000000 +0000
+++ Source/JavaScriptCore/wtf/MathExtras.h
@@ -277,7 +277,7 @@ inline bool isWithinIntRange(float x)
     return x > static_cast<float>(std::numeric_limits<int>::min()) && x < static_cast<float>(std::numeric_limits<int>::max());
 }
 
-#if !COMPILER(MSVC) && !COMPILER(RVCT) && !OS(SOLARIS)
+#if !COMPILER(MSVC) && !COMPILER(RVCT) && !(OS(SOLARIS) && COMPILER(GCC) && (GCC_VERSION < 40600))
 using std::isfinite;
 using std::isinf;
 using std::isnan;
