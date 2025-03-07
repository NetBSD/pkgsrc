$NetBSD: patch-src_sort__r.h,v 1.4 2025/03/07 04:45:42 mrg Exp $

SunOS support
https://github.com/dajobe/raptor/pull/57

Fix NetBSD support after NetBSD added sort_r().

--- src/sort_r.h.orig	2017-07-01 13:53:27.000000000 -0700
+++ src/sort_r.h	2025-03-06 11:25:23.846999574 -0800
@@ -22,14 +22,15 @@
 #if (defined __APPLE__ || defined __MACH__ || defined __DARWIN__ || \
      defined __FreeBSD__ || defined __BSD__ || defined __bsdi__ || \
      defined OpenBSD3_1 || defined OpenBSD3_9 || defined __OpenBSD__ || \
-     defined __NetBSD__ || \
      defined __DragonFly__ || \
      defined AMIGA)
 #  define _SORT_R_BSD
 #elif (defined _GNU_SOURCE || defined __gnu_hurd__ || defined __GNU__ || \
        defined __linux__ || defined __MINGW32__ || defined __GLIBC__ || \
-       defined __CYGWIN__)
+       defined __CYGWIN__ || defined __NetBSD__)
 #  define _SORT_R_LINUX
+#elif defined __sun
+#  define _SORT_R_SUN
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
 #else
@@ -87,6 +88,11 @@
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
+  #elif defined _SORT_R_SUN
+
+     extern void qsort_r(void *base, size_t nel, size_t width,
+         int (*compar_arg)(const void *, const void *, void *), void *arg);
+
   #endif
 
   /* implementation */
@@ -106,6 +112,10 @@
       tmp.compar = compar;
       qsort_r(base, nel, width, &tmp, sort_r_arg_swap);
 
+    #elif defined _SORT_R_SUN
+
+      qsort_r(base, nel, width, compar, arg);
+
     #else /* defined _SORT_R_WINDOWS */
 
       struct sort_r_data tmp;
@@ -121,5 +131,6 @@
 #undef _SORT_R_WINDOWS
 #undef _SORT_R_LINUX
 #undef _SORT_R_BSD
+#undef _SORT_R_SUN
 
 #endif /* SORT_R_H_ */
