$NetBSD: patch-Source_JavaScriptCore_assembler_ARMv7Assembler.h,v 1.2 2019/09/10 22:10:04 leot Exp $

Add support for NetBSD.

--- Source/JavaScriptCore/assembler/ARMv7Assembler.h.orig	2019-08-28 11:46:27.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMv7Assembler.h
@@ -28,6 +28,11 @@
 
 #if ENABLE(ASSEMBLER) && CPU(ARM_THUMB2)
 
+#if OS(NETBSD)
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 #include "AssemblerBuffer.h"
 #include "AssemblerCommon.h"
 #include "RegisterInfo.h"
@@ -2394,6 +2399,11 @@ public:
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(NETBSD)
+	struct arm_sync_icache_args arg;
+	arg.addr = reinterpret_cast<uintptr_t>(code);
+	arg.len = size;
+	sysarch(ARM_SYNC_ICACHE, (void *)&arg);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
