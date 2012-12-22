$NetBSD: patch-util_neo__err.h,v 1.1 2012/12/22 02:25:57 joerg Exp $

Dropping the comma before __VA_ARGS__ when the list is empty is a GCC
language extension.

--- util/neo_err.h.orig	2012-12-21 19:08:49.000000000 +0000
+++ util/neo_err.h
@@ -84,8 +84,8 @@ typedef struct _neo_err 
  *          NEOERR fails
  */
 #if defined(USE_C99_VARARG_MACROS)
-#define nerr_raise(e,f,...) \
-   nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,__VA_ARGS__)
+#define nerr_raise(e,...) \
+   nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,__VA_ARGS__)
 #elif defined(USE_GNUC_VARARG_MACROS)
 #define nerr_raise(e,f,a...) \
    nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,##a)
@@ -98,8 +98,8 @@ NEOERR *nerr_raisef (const char *func, c
 
 
 #if defined(USE_C99_VARARG_MACROS)
-#define nerr_raise_errno(e,f,...) \
-   nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,__VA_ARGS__)
+#define nerr_raise_errno(e,...) \
+   nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,__VA_ARGS__)
 #elif defined(USE_GNUC_VARARG_MACROS)
 #define nerr_raise_errno(e,f,a...) \
    nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,##a)
