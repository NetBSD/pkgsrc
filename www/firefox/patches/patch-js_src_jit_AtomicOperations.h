$NetBSD: patch-js_src_jit_AtomicOperations.h,v 1.2 2016/08/06 08:46:59 ryoon Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1232150

--- js/src/jit/AtomicOperations.h.orig	2016-07-25 20:22:07.000000000 +0000
+++ js/src/jit/AtomicOperations.h
@@ -328,6 +328,8 @@ AtomicOperations::isLockfree(int32_t siz
 # include "jit/mips-shared/AtomicOperations-mips-shared.h"
 #elif defined(__ppc__) || defined(__PPC__)
 # include "jit/none/AtomicOperations-ppc.h"
+#elif defined(__sparc__)
+# include "jit/none/AtomicOperations-sparc.h"
 #elif defined(JS_CODEGEN_NONE)
   // You can disable the JIT with --disable-ion but you must still
   // provide the atomic operations that will be used by the JS engine.
