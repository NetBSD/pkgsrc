$NetBSD: patch-src_sort__r.h,v 1.1 2022/04/12 13:20:05 tnn Exp $

SunOS support

--- src/sort_r.h.orig	2014-10-09 23:00:44.000000000 +0000
+++ src/sort_r.h
@@ -29,6 +29,8 @@ void sort_r(void *base, size_t nel, size
 #elif (defined _GNU_SOURCE || defined __gnu_hurd__ || defined __GNU__ || \
        defined __linux__ || defined __MINGW32__ || defined __GLIBC__)
 #  define _SORT_R_LINUX
+#elif defined __sun
+#  define _SORT_R_SUN
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
 #else
@@ -86,6 +88,11 @@ void sort_r(void *base, size_t nel, size
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
+  #elif defined _SORT_R_SUN
+
+     extern void qsort_r(void *base, size_t nel, size_t width,
+         int (*compar_arg)(const void *, const void *, void *), void *arg);
+
   #endif
 
   /* implementation */
@@ -105,6 +112,10 @@ void sort_r(void *base, size_t nel, size
       tmp.compar = compar;
       qsort_r(base, nel, width, &tmp, sort_r_arg_swap);
 
+    #elif defined _SORT_R_SUN
+
+      qsort_r(base, nel, width, compar, arg);
+
     #else /* defined _SORT_R_WINDOWS */
 
       struct sort_r_data tmp;
@@ -120,5 +131,6 @@ void sort_r(void *base, size_t nel, size
 #undef _SORT_R_WINDOWS
 #undef _SORT_R_LINUX
 #undef _SORT_R_BSD
+#undef _SORT_R_SUN
 
 #endif /* SORT_R_H_ */
