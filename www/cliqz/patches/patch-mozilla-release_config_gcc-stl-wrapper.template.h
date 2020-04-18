$NetBSD: patch-mozilla-release_config_gcc-stl-wrapper.template.h,v 1.2 2020/04/18 07:58:36 fox Exp $

Taken from www/firefox

--- mozilla-release/config/gcc-stl-wrapper.template.h.orig	2020-04-03 19:34:34.000000000 +0000
+++ mozilla-release/config/gcc-stl-wrapper.template.h
@@ -28,8 +28,8 @@
 #endif
 
 // Don't include mozalloc for cstdlib. See bug 1245076.
-#ifndef moz_dont_include_mozalloc_for_cstdlib
-#  define moz_dont_include_mozalloc_for_cstdlib
+#ifndef moz_dont_include_mozalloc_for_${HEADER}
+#  define moz_dont_include_mozalloc_for_${HEADER}
 #endif
 
 #ifndef moz_dont_include_mozalloc_for_type_traits
@@ -43,7 +43,7 @@
 // Include mozalloc after the STL header and all other headers it includes
 // have been preprocessed.
 #if !defined(MOZ_INCLUDE_MOZALLOC_H) && \
-    !defined(moz_dont_include_mozalloc_for_${HEADER})
+    !defined(moz_dont_include_mozalloc_for_cstdlib)
 #  define MOZ_INCLUDE_MOZALLOC_H
 #  define MOZ_INCLUDE_MOZALLOC_H_FROM_${HEADER}
 #endif
@@ -72,4 +72,6 @@
 #  include "mozilla/throw_gcc.h"
 #endif
 
+#undef moz_dont_include_mzalloc_for_${HEADER}
+
 #endif  // if mozilla_${HEADER}_h
