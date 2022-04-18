$NetBSD: patch-src_3rdparty_chromium_base_allocator_allocator__shim__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc
@@ -595,7 +595,7 @@ static size_t GetAllocatedSize(void* ptr
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_size(ptr);
 }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_usable_size(ptr);
 }
