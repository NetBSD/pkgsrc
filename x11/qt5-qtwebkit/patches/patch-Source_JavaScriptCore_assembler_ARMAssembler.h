$NetBSD: patch-Source_JavaScriptCore_assembler_ARMAssembler.h,v 1.2 2018/01/17 19:37:33 markd Exp $

* Add NetBSD support

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2017-06-04 20:16:05.000000000 +0000
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
@@ -1128,6 +1132,11 @@ namespace JSC {
                 linuxPageFlush(current, current + page);
 
             linuxPageFlush(current, end);
+#elif OS(NETBSD)
+            struct arm_sync_icache_args args;
+            args.addr = reinterpret_cast<uintptr_t>(code);
+            args.len = size;
+            sysarch(ARM_SYNC_ICACHE, &args);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
