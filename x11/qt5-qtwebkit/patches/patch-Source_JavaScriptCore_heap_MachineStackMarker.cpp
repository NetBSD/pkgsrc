$NetBSD: patch-Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.2 2018/01/17 19:37:33 markd Exp $

Support NetBSD

XXXX - currently only did CPU(X86_64) and guessed those values.
    rest are currently jsut copied from FreeBSD

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2017-06-04 20:16:05.000000000 +0000
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -665,6 +665,22 @@ void* MachineThreads::Thread::Registers:
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_ebp);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_RBP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_FP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_gpregs.gp_x[29]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_regs[30]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -747,6 +763,22 @@ void* MachineThreads::Thread::Registers:
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_eip);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_RIP]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_PC]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_gpregs.gp_elr);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_pc);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -838,6 +870,22 @@ void* MachineThreads::Thread::Registers:
 #error Unknown Architecture
 #endif
 
+#elif OS(NETBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_esi);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_gpregs.gp_x[4]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.mc_regs[12]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
