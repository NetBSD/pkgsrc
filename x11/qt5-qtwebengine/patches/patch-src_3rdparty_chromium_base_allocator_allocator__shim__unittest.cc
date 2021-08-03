$NetBSD: patch-src_3rdparty_chromium_base_allocator_allocator__shim__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc
@@ -557,7 +557,7 @@ static size_t GetAllocatedSize(void* ptr
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_size(ptr);
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_usable_size(ptr);
 }
