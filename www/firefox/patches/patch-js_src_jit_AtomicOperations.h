$NetBSD: patch-js_src_jit_AtomicOperations.h,v 1.1 2016/05/04 16:22:35 martin Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1232150

--- js/src/jit/AtomicOperations.h.orig	2016-04-22 02:37:26.000000000 +0200
+++ js/src/jit/AtomicOperations.h	2016-05-02 18:09:00.162942120 +0200
@@ -316,6 +316,8 @@ AtomicOperations::isLockfree(int32_t siz
     || defined(__ppc64le__) || defined(__PPC64LE__) \
     || defined(__ppc__) || defined(__PPC__)
 # include "jit/none/AtomicOperations-ppc.h"
+#elif defined(__sparc__)
+# include "jit/none/AtomicOperations-sparc.h"
 #elif defined(JS_CODEGEN_NONE)
 # include "jit/none/AtomicOperations-none.h"
 #elif defined(JS_CODEGEN_X86) || defined(JS_CODEGEN_X64)
