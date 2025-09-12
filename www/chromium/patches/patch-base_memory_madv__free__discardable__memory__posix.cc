$NetBSD: patch-base_memory_madv__free__discardable__memory__posix.cc,v 1.7 2025/09/12 16:02:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/madv_free_discardable_memory_posix.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -298,6 +298,10 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -314,6 +318,7 @@ bool MadvFreeDiscardableMemoryPosix::IsR
     }
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
