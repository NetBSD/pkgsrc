$NetBSD: patch-src_sort__r.h,v 1.2 2023/03/07 10:42:16 wiz Exp $

SunOS support

--- src/sort_r.h.orig	2017-07-01 20:53:27.000000000 +0000
+++ src/sort_r.h
@@ -30,6 +30,8 @@ void sort_r(void *base, size_t nel, size
        defined __linux__ || defined __MINGW32__ || defined __GLIBC__ || \
        defined __CYGWIN__)
 #  define _SORT_R_LINUX
+#elif defined __sun
+#  define _SORT_R_SUN
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
 #else
@@ -87,6 +89,11 @@ void sort_r(void *base, size_t nel, size
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
+  #elif defined _SORT_R_SUN
+
+     extern void qsort_r(void *base, size_t nel, size_t width,
+         int (*compar_arg)(const void *, const void *, void *), void *arg);
+
   #endif
 
   /* implementation */
@@ -106,6 +113,10 @@ void sort_r(void *base, size_t nel, size
       tmp.compar = compar;
       qsort_r(base, nel, width, &tmp, sort_r_arg_swap);
 
+    #elif defined _SORT_R_SUN
+
+      qsort_r(base, nel, width, compar, arg);
+
     #else /* defined _SORT_R_WINDOWS */
 
       struct sort_r_data tmp;
@@ -121,5 +132,6 @@ void sort_r(void *base, size_t nel, size
 #undef _SORT_R_WINDOWS
 #undef _SORT_R_LINUX
 #undef _SORT_R_BSD
+#undef _SORT_R_SUN
 
 #endif /* SORT_R_H_ */
