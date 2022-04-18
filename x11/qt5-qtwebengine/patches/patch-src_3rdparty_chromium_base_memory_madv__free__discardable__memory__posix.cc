$NetBSD: patch-src_3rdparty_chromium_base_memory_madv__free__discardable__memory__posix.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc
@@ -296,7 +296,7 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
