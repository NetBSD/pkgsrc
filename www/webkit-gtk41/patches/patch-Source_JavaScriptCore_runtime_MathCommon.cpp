$NetBSD: patch-Source_JavaScriptCore_runtime_MathCommon.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/JavaScriptCore/runtime/MathCommon.cpp.orig	2025-08-08 09:17:51.608548200 +0000
+++ Source/JavaScriptCore/runtime/MathCommon.cpp
@@ -626,8 +626,8 @@ static inline double roundeven(double operand)
 }
 #endif
 
-JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_roundeven, float, (float operand)) { return roundevenf(operand); }
-JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_roundeven, double, (double operand)) { return roundeven(operand); }
+JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_roundeven, float, (float operand)) { return f32_roundeven(operand); }
+JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_roundeven, double, (double operand)) { return f64_roundeven(operand); }
 JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_trunc, float, (float operand)) { return std::trunc(operand); }
 JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_trunc, double, (double operand)) { return std::trunc(operand); }
 
