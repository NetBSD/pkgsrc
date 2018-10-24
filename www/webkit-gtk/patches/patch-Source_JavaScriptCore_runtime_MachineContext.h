$NetBSD: patch-Source_JavaScriptCore_runtime_MachineContext.h,v 1.1 2018/10/24 18:31:07 leot Exp $

Add support for NetBSD.

--- Source/JavaScriptCore/runtime/MachineContext.h.orig	2018-08-21 16:06:10.000000000 +0000
+++ Source/JavaScriptCore/runtime/MachineContext.h
@@ -188,6 +188,22 @@ static inline void*& stackPointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_UESP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 #if CPU(X86)
@@ -335,6 +351,22 @@ static inline void*& framePointerImpl(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EBP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RBP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_S8]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -482,6 +514,22 @@ static inline void*& instructionPointerI
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EIP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RIP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EPC]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -639,6 +687,22 @@ inline void*& argumentPointer<1>(mcontex
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_EDX]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_RSI]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R1]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_X1]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_A1]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -756,6 +820,22 @@ inline void*& llintInstructionPointer(mc
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_ESI]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_X4]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_T4]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || defined(__GLIBC__) || defined(__BIONIC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
