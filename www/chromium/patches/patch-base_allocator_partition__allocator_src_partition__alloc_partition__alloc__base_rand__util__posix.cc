$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_rand__util__posix.cc,v 1.1 2025/02/06 09:57:39 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/rand_util_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/rand_util_posix.cc
@@ -102,6 +102,10 @@ void RandBytes(void* output, size_t outp
   if (getentropy(output, output_length) == 0) {
     return;
   }
+#elif PA_BUILDFLAG(IS_BSD)
+  if (getentropy(output, output_length) == 0) {
+    return;
+  }
 #endif
   // If getrandom(2) above returned with an error and the /dev/urandom fallback
   // took place on Linux/ChromeOS bots, they would fail with a CHECK in
