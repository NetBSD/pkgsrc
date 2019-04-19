$NetBSD: patch-mozilla-release_ipc_chromium_src_base_lock__impl__posix.cc,v 1.1 2019/04/19 14:02:03 fox Exp $

- Fix build on NetBSD 7.1 (which doesn't have PTHREAD_PRIO_INHERIT)

Original patch from tsutsui, imported from www/firefox

--- mozilla-release/ipc/chromium/src/base/lock_impl_posix.cc.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/ipc/chromium/src/base/lock_impl_posix.cc
@@ -22,7 +22,7 @@ namespace internal {
 // Lock::PriorityInheritanceAvailable still must be checked as the code may
 // compile but the underlying platform still may not correctly support priority
 // inheritance locks.
-#if defined(OS_NACL) || defined(OS_ANDROID)
+#if defined(OS_NACL) || defined(OS_ANDROID) || (defined(__NetBSD__) && !defined(PTHREAD_PRIO_INHERIT))
 #  define PRIORITY_INHERITANCE_LOCKS_POSSIBLE() 0
 #else
 #  define PRIORITY_INHERITANCE_LOCKS_POSSIBLE() 1
