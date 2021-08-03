$NetBSD: patch-src_3rdparty_chromium_base_memory_madv__free__discardable__memory__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/memory/madv_free_discardable_memory_posix.cc
@@ -292,7 +292,7 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
