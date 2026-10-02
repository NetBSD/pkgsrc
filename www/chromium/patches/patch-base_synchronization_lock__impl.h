$NetBSD: patch-base_synchronization_lock__impl.h,v 1.28 2026/10/02 11:43:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/synchronization/lock_impl.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ base/synchronization/lock_impl.h
@@ -129,6 +129,10 @@ void LockImpl::Unlock() {
 }
 
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
+#endif
 
 #if DCHECK_IS_ON()
 BASE_EXPORT void dcheck_trylock_result(int rv);
@@ -149,6 +153,9 @@ void LockImpl::Unlock() {
   dcheck_unlock_result(rv);
 #endif
 }
+#if BUILDFLAG(IS_FREEBSD)
+#pragma GCC diagnostic pop
+#endif
 #endif
 
 // This is an implementation used for AutoLock templated on the lock type.
