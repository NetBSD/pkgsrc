$NetBSD: patch-Source_JavaScriptCore_jit_ThunkGenerators.cpp,v 1.1 2018/08/01 15:01:08 maya Exp $

Treat netbsd as linux for JIT purposes.

--- Source/JavaScriptCore/jit/ThunkGenerators.cpp.orig	2017-06-04 20:16:05.000000000 +0000
+++ Source/JavaScriptCore/jit/ThunkGenerators.cpp
@@ -633,7 +633,7 @@ MacroAssemblerCodeRef sqrtThunkGenerator
 enum MathThunkCallingConvention { };
 typedef MathThunkCallingConvention(*MathThunk)(MathThunkCallingConvention);
 
-#if CPU(X86_64) && COMPILER(GCC_OR_CLANG) && (OS(DARWIN) || OS(LINUX))
+#if CPU(X86_64) && COMPILER(GCC_OR_CLANG) && (OS(DARWIN) || OS(LINUX) || OS(NETBSD))
 
 #define defineUnaryDoubleOpWrapper(function) \
     asm( \
@@ -651,7 +651,7 @@ typedef MathThunkCallingConvention(*Math
     } \
     static MathThunk UnaryDoubleOpWrapper(function) = &function##Thunk;
 
-#elif CPU(X86) && COMPILER(GCC_OR_CLANG) && OS(LINUX) && defined(__PIC__)
+#elif CPU(X86) && COMPILER(GCC_OR_CLANG) && (OS(LINUX) || OS(NETBSD)) && defined(__PIC__)
 #define defineUnaryDoubleOpWrapper(function) \
     asm( \
         ".text\n" \
@@ -675,7 +675,7 @@ typedef MathThunkCallingConvention(*Math
     } \
     static MathThunk UnaryDoubleOpWrapper(function) = &function##Thunk;
 
-#elif CPU(X86) && COMPILER(GCC_OR_CLANG) && (OS(DARWIN) || OS(LINUX))
+#elif CPU(X86) && COMPILER(GCC_OR_CLANG) && (OS(DARWIN) || OS(LINUX) || OS(NETBSD))
 #define defineUnaryDoubleOpWrapper(function) \
     asm( \
         ".text\n" \
