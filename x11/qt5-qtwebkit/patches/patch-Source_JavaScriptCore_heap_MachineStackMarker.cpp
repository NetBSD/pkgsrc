$NetBSD: patch-Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.4 2022/03/28 14:38:50 tnn Exp $

Support NetBSD on x86, arm, arm64 and mips.
Support SunOS (Illumos-derived) on x86_64 

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -54,6 +54,7 @@
 
 #if OS(SOLARIS)
 #include <thread.h>
+#include <sys/regset.h>
 #else
 #include <pthread.h>
 #endif
@@ -483,7 +484,7 @@ size_t MachineThreads::Thread::getRegist
     return sizeof(CONTEXT);
 #elif USE(PTHREADS)
     pthread_attr_init(&regs.attribute);
-#if HAVE(PTHREAD_NP_H) || OS(NETBSD)
+#if HAVE(PTHREAD_NP_H) || OS(NETBSD) || OS(SOLARIS) /* XXX this is OK for Illumos, but not Oracle */
 #if !OS(OPENBSD)
     // e.g. on FreeBSD 5.4, neundorf@kde.org
     pthread_attr_get_np(platformThread, &regs.attribute);
@@ -665,6 +666,31 @@ void* MachineThreads::Thread::Registers:
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
+#elif OS(SOLARIS)
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.gregs[REG_EBP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.gregs[REG_RBP]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -747,6 +773,31 @@ void* MachineThreads::Thread::Registers:
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
+#elif OS(SOLARIS)
+#if CPU(X86)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.gregs[REG_EIP]);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.gregs[REG_RIP]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -838,6 +889,31 @@ void* MachineThreads::Thread::Registers:
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
+#elif OS(SOLARIS)
+#if CPU(X86)
+#error fixme
+#elif CPU(X86_64)
+    return reinterpret_cast<void*>((uintptr_t) regs.machineContext.gregs[REG_R8]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif defined(__GLIBC__)
 
 // The following sequence depends on glibc's sys/ucontext.h.
