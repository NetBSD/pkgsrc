$NetBSD: patch-config_gcc-stl-wrapper.template.h,v 1.8 2026/11/03 16:46:29 ryoon Exp $

--- config/gcc-stl-wrapper.template.h.orig	2026-10-22 17:49:07.000000000 +0000
+++ config/gcc-stl-wrapper.template.h
@@ -27,8 +27,8 @@
 // limits) and bug 1694575 (iosfwd).
 // Please be careful when adding more exceptions, especially regarding
 // the header not directly or indirectly including <new>.
-#ifndef moz_dont_include_mozalloc_for_cstdlib
-#  define moz_dont_include_mozalloc_for_cstdlib
+#ifndef moz_dont_include_mozalloc_for_${HEADER}
+#  define moz_dont_include_mozalloc_for_${HEADER}
 #endif
 
 #ifndef moz_dont_include_mozalloc_for_cmath
@@ -78,5 +78,7 @@
 #ifndef mozilla_throw_gcc_h
 #  include "mozilla/throw_gcc.h"
 #endif
+
+#undef moz_dont_include_mzalloc_for_${HEADER}
 
 #endif  // if mozilla_${HEADER}_h
