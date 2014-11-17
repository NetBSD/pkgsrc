$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_jit_ExecutableAllocator.h,v 1.1 2014/11/17 11:54:42 jmcneill Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h.orig	2014-04-10 18:37:11.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/jit/ExecutableAllocator.h
@@ -66,6 +66,10 @@ extern "C" __declspec(dllimport) void Ca
 #include <wtf/brew/RefPtrBrew.h>
 #endif
 
+#if CPU(ARM) && OS(NETBSD)
+#include <machine/sysarch.h>
+#endif
+
 #define JIT_ALLOCATOR_PAGE_SIZE (ExecutableAllocator::pageSize)
 #define JIT_ALLOCATOR_LARGE_ALLOC_SIZE (ExecutableAllocator::pageSize * 4)
 
@@ -326,6 +330,14 @@ public:
         syscall(__NR_cacheflush, reinterpret_cast<unsigned>(code), size, CACHEFLUSH_D_WB | CACHEFLUSH_I);
 #endif
     }
+#elif CPU(ARM) && OS(NETBSD)
+    static void cacheFlush(void *code, size_t size)
+    {
+        struct arm_sync_icache_args args;
+        args.addr = reinterpret_cast<uintptr_t>(code);
+        args.len = size;
+        sysarch(ARM_SYNC_ICACHE, &args);
+    }
 #else
     #error "The cacheFlush support is missing on this platform."
 #endif
