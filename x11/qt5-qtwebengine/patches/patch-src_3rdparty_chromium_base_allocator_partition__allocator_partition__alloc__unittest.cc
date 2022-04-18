$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_partition__alloc__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -333,9 +333,13 @@ void FreeFullPage(PartitionRoot<base::in
   }
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool CheckPageInCore(void* ptr, bool in_core) {
+#if defined(OS_BSD)
+  char ret = 0;
+#else
   unsigned char ret = 0;
+#endif
   EXPECT_EQ(0, mincore(ptr, SystemPageSize(), &ret));
   return in_core == (ret & 1);
 }
