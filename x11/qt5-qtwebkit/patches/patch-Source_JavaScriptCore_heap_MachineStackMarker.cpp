$NetBSD: patch-Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.3 2019/12/13 09:48:02 mrg Exp $

Support NetBSD on x86, arm, arm64 and mips.

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2019-06-26 09:25:02.000000000 -0700
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp	2019-12-12 19:40:05.519044971 -0800
@@ -665,6 +665,22 @@
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_EBP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_RBP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_FP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_X29]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_S8]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -747,6 +763,22 @@
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_EIP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_RIP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_PC]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_ELR]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_EPC]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -838,6 +870,22 @@
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_ESI]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_R4]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_T4]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
