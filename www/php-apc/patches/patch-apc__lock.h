$NetBSD: patch-apc__lock.h,v 1.1 2011/06/20 15:09:52 taca Exp $

- Fix fcntl lock error from repository r311339.

--- apc_lock.h.orig	2011-05-14 22:14:56.000000000 +0000
+++ apc_lock.h
@@ -154,7 +154,7 @@
 # define apc_lck_nb_lock(a)    apc_fcntl_nonblocking_lock(a TSRMLS_CC)
 # define apc_lck_rdlock(a)     apc_fcntl_rdlock(a TSRMLS_CC)
 # define apc_lck_unlock(a)     apc_fcntl_unlock(a TSRMLS_CC)
-# define apc_lck_rdunlock(a)   apc_fcntl_unlock(&a TSRMLS_CC)
+# define apc_lck_rdunlock(a)   apc_fcntl_unlock(a TSRMLS_CC)
 #endif
 
 #endif
