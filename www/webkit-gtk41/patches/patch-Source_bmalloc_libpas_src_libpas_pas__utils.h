$NetBSD: patch-Source_bmalloc_libpas_src_libpas_pas__utils.h,v 1.1 2026/09/22 12:27:03 wiz Exp $

In file included from /tmp/www/webkit-gtk41/work/webkitgtk-2.54.0/cmake-pkgsrc-build/bmalloc/Headers/bmalloc/pas_utils.h:45,
                 from /tmp/www/webkit-gtk41/work/webkitgtk-2.54.0/cmake-pkgsrc-build/bmalloc/Headers/bmalloc/pas_process.h:29,
                 from /tmp/www/webkit-gtk41/work/webkitgtk-2.54.0/Source/WTF/wtf/Threading.cpp:30:
/usr/include/gcc-14/stdatomic.h:40:9: error: '_Atomic' does not name a type; did you mean 'Atomic'?
   40 | typedef _Atomic _Bool atomic_bool;
      |         ^~~~~~~
      |         Atomic

--- Source/bmalloc/libpas/src/libpas/pas_utils.h.orig	2026-07-24 08:02:56.317823600 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_utils.h
@@ -42,7 +42,12 @@
 #endif
 
 #include <limits.h>
+#ifdef __cplusplus
+#include <atomic>
+using namespace std;
+#else
 #include <stdatomic.h>
+#endif
 #include <stdbool.h>
 #include <stdint.h>
 #include <string.h>
