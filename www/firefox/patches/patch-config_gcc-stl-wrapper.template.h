$NetBSD: patch-config_gcc-stl-wrapper.template.h,v 1.7 2026/08/24 12:51:47 ryoon Exp $

--- config/gcc-stl-wrapper.template.h.orig	2026-04-15 13:12:19.000000000 +0000
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
@@ -50,7 +50,7 @@
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
-    !defined(moz_dont_include_mozalloc_for_${HEADER})
+    !defined(moz_dont_include_mozalloc_for_${HEADER})
 #  define MOZ_INCLUDE_MOZALLOC_H
 #  define MOZ_INCLUDE_MOZALLOC_H_FROM_${HEADER}
 #endif
@@ -78,5 +78,7 @@
 #ifndef mozilla_throw_gcc_h
 #  include "mozilla/throw_gcc.h"
 #endif
+
+#undef moz_dont_include_mzalloc_for_${HEADER}
 
 #endif  // if mozilla_${HEADER}_h
