$NetBSD: patch-src_rapidfuzz_distance___initialize__cpp.cxx,v 1.1 2026/09/02 03:37:29 ryoon Exp $

--- src/rapidfuzz/distance/_initialize_cpp.cxx.orig	2022-11-09 12:37:21.000000000 +0000
+++ src/rapidfuzz/distance/_initialize_cpp.cxx
@@ -1221,12 +1221,14 @@ static int __Pyx_init_tpflags_variables(void) {
     #define _USE_MATH_DEFINES
   #endif
 #endif
-#include <math.h>
+#include <cmath>
 #if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
 #define __Pyx_truncl trunc
 #else
 #define __Pyx_truncl truncl
 #endif
+
+using std::isfinite;
 
 #ifndef CYTHON_CLINE_IN_TRACEBACK_RUNTIME
 #define CYTHON_CLINE_IN_TRACEBACK_RUNTIME 0
