$NetBSD: patch-Source_JavaScriptCore_runtime_MathCommon.cpp,v 1.2 2026/09/22 12:27:02 wiz Exp $

--- Source/JavaScriptCore/runtime/MathCommon.cpp.orig	2026-07-24 08:02:50.857928800 +0000
+++ Source/JavaScriptCore/runtime/MathCommon.cpp
@@ -602,8 +602,8 @@ JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_nearest, double,
     return roundeven(operand);
 }
 
-JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_roundeven, float, (float operand)) { return roundevenf(operand); }
-JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_roundeven, double, (double operand)) { return roundeven(operand); }
+JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_roundeven, float, (float operand)) { return f32_roundeven(operand); }
+JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_roundeven, double, (double operand)) { return f64_roundeven(operand); }
 JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f32_trunc, float, (float operand)) { return std::trunc(operand); }
 JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_trunc, double, (double operand)) { return std::trunc(operand); }
 
