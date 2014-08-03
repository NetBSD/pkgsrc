$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.1 2014/08/03 22:07:39 wiz Exp $

Remove bogus Solaris check.

--- Source/WTF/wtf/MathExtras.h.orig	2012-10-16 15:22:38.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -288,7 +288,7 @@ inline bool isWithinIntRange(float x)
     return x > static_cast<float>(std::numeric_limits<int>::min()) && x < static_cast<float>(std::numeric_limits<int>::max());
 }
 
-#if !COMPILER(MSVC) && !COMPILER(RVCT) && !OS(SOLARIS)
+#if !COMPILER(MSVC) && !COMPILER(RVCT)
 using std::isfinite;
 #if !COMPILER_QUIRK(GCC11_GLOBAL_ISINF_ISNAN)
 using std::isinf;
