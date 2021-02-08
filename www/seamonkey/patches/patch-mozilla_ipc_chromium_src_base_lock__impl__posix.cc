$NetBSD: patch-mozilla_ipc_chromium_src_base_lock__impl__posix.cc,v 1.2 2021/02/08 12:26:20 ryoon Exp $

--- ipc/chromium/src/base/lock_impl_posix.cc.orig	2020-02-17 23:37:52.000000000 +0000
+++ ipc/chromium/src/base/lock_impl_posix.cc
@@ -20,7 +20,7 @@ namespace internal {
 // Lock::PriorityInheritanceAvailable still must be checked as the code may
 // compile but the underlying platform still may not correctly support priority
 // inheritance locks.
-#if defined(OS_NACL) || defined(OS_ANDROID)
+#if defined(OS_NACL) || defined(OS_ANDROID) || (defined(__NetBSD__) && !defined(PTHREAD_PRIO_INHERIT))
 #define PRIORITY_INHERITANCE_LOCKS_POSSIBLE() 0
 #else
 #define PRIORITY_INHERITANCE_LOCKS_POSSIBLE() 1
