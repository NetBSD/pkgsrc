$NetBSD: patch-platform_js_src_jit_AtomicOperations.h,v 1.1 2024/09/20 05:45:44 martin Exp $

User powerpc atomic operations on NetBSD/powerpc

--- platform/js/src/jit/AtomicOperations.h.orig	2024-09-05 10:13:09.000000000 +0200
+++ platform/js/src/jit/AtomicOperations.h	2024-09-19 20:30:25.512218030 +0200
@@ -325,7 +325,7 @@
 # include "jit/arm64/AtomicOperations-arm64.h"
 #elif defined(JS_CODEGEN_MIPS32) || defined(JS_CODEGEN_MIPS64)
 # include "jit/mips-shared/AtomicOperations-mips-shared.h"
-#elif defined(__ppc__) || defined(__PPC__)
+#elif defined(__ppc__) || defined(__PPC__) || defined(__powerpc__)
 # include "jit/none/AtomicOperations-ppc.h"
 #elif defined(__sparc__)
 # include "jit/none/AtomicOperations-sparc.h"
