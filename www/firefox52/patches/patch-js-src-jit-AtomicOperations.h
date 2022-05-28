$NetBSD: patch-js-src-jit-AtomicOperations.h,v 1.1 2022/05/28 18:31:13 martin Exp $

Add preprocessor defines used by gcc/clang on NetBSD for powerpc.

--- js/src/jit/AtomicOperations.h.orig	2017-04-11 04:13:15.000000000 +0200
+++ js/src/jit/AtomicOperations.h	2022-05-28 20:07:39.621923780 +0200
@@ -326,7 +326,7 @@ AtomicOperations::isLockfree(int32_t siz
 # include "jit/arm64/AtomicOperations-arm64.h"
 #elif defined(JS_CODEGEN_MIPS32) || defined(JS_CODEGEN_MIPS64)
 # include "jit/mips-shared/AtomicOperations-mips-shared.h"
-#elif defined(__ppc__) || defined(__PPC__)
+#elif defined(__ppc__) || defined(__PPC__) || defined(__powerpc__)
 # include "jit/none/AtomicOperations-ppc.h"
 #elif defined(__sparc__)
 # include "jit/none/AtomicOperations-sparc.h"
@@ -337,7 +337,7 @@ AtomicOperations::isLockfree(int32_t siz
   // C++ realizations of atomics.  These operations cannot be written
   // in portable C++, hence the default here is to crash.  See the
   // top of the file for more guidance.
-# if defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64le__) || defined(__PPC64LE__)
+# if defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64le__) || defined(__PPC64LE__) || defined(__powerpc__)
 #  include "jit/none/AtomicOperations-ppc.h"
 # elif defined(__aarch64__)
 #  include "jit/arm64/AtomicOperations-arm64.h"
