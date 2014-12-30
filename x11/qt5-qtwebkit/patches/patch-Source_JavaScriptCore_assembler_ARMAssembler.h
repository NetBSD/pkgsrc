$NetBSD: patch-Source_JavaScriptCore_assembler_ARMAssembler.h,v 1.1 2014/12/30 17:23:47 adam Exp $

* Add NetBSD support

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2013-11-27 01:01:49.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -27,6 +27,10 @@
 #ifndef ARMAssembler_h
 #define ARMAssembler_h
 
+#if OS(NETBSD)
+#include <machine/sysarch.h>
+#endif
+
 #if ENABLE(ASSEMBLER) && CPU(ARM_TRADITIONAL)
 
 #include "AssemblerBufferWithConstantPool.h"
@@ -1069,6 +1073,11 @@ namespace JSC {
             UNUSED_PARAM(size);
 #elif OS(QNX)
             msync(code, size, MS_INVALIDATE_ICACHE);
+#elif OS(NETBSD)
+            struct arm_sync_icache_args args;
+            args.addr = reinterpret_cast<uintptr_t>(code);
+            args.len = size;
+            sysarch(ARM_SYNC_ICACHE, &args);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
