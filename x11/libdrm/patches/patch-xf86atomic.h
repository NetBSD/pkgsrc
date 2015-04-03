$NetBSD: patch-xf86atomic.h,v 1.1 2015/04/03 16:09:38 tnn Exp $

Fix a broken macro definition.

--- xf86atomic.h.orig	2015-03-18 17:33:36.000000000 +0000
+++ xf86atomic.h
@@ -93,7 +93,7 @@ typedef struct { LIBDRM_ATOMIC_TYPE atom
 # define atomic_read(x) (int) ((x)->atomic)
 # define atomic_set(x, val) ((x)->atomic = (LIBDRM_ATOMIC_TYPE)(val))
 # define atomic_inc(x) (atomic_inc_uint (&(x)->atomic))
-# define atomic_inc_return (atomic_inc_uint_nv(&(x)->atomic))
+# define atomic_inc_return(x) (atomic_inc_uint_nv(&(x)->atomic))
 # define atomic_dec_and_test(x) (atomic_dec_uint_nv(&(x)->atomic) == 0)
 # define atomic_add(x, v) (atomic_add_int(&(x)->atomic, (v)))
 # define atomic_dec(x, v) (atomic_add_int(&(x)->atomic, -(v)))
