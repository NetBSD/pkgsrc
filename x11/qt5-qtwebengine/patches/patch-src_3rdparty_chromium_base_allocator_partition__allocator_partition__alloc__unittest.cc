$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_partition__alloc__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -313,9 +313,13 @@ void FreeFullPage(PartitionRoot<base::in
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool CheckPageInCore(void* ptr, bool in_core) {
+#if defined(OS_BSD)
+  char ret = 0;
+#else
   unsigned char ret = 0;
+#endif
   EXPECT_EQ(0, mincore(ptr, kSystemPageSize, &ret));
   return in_core == (ret & 1);
 }
