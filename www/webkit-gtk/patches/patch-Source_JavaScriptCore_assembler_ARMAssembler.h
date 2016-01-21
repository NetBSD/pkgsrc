$NetBSD: patch-Source_JavaScriptCore_assembler_ARMAssembler.h,v 1.6 2016/01/21 13:42:33 leot Exp $

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2016-01-20 12:12:59.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -29,6 +29,11 @@
 
 #if ENABLE(ASSEMBLER) && CPU(ARM_TRADITIONAL)
 
+#if defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 #include "AssemblerBufferWithConstantPool.h"
 #include "JITCompilationEffort.h"
 #include <wtf/Assertions.h>
@@ -1128,6 +1133,11 @@ namespace JSC {
                 linuxPageFlush(current, current + page);
 
             linuxPageFlush(current, end);
+#elif defined(__NetBSD__)
+            struct arm_sync_icache_args arg;
+            arg.addr = reinterpret_cast<uintptr_t>(code);
+            arg.len = size;
+            sysarch(ARM_SYNC_ICACHE, (void *)&arg);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
