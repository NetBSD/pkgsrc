$NetBSD: patch-base_memory_madv__free__discardable__memory__posix.cc,v 1.19 2026/05/10 15:29:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/madv_free_discardable_memory_posix.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -293,6 +293,10 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -309,6 +313,7 @@ bool MadvFreeDiscardableMemoryPosix::IsR
     }
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
