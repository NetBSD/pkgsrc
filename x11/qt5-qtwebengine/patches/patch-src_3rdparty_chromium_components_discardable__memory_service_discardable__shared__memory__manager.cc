$NetBSD: patch-src_3rdparty_chromium_components_discardable__memory_service_discardable__shared__memory__manager.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -33,7 +33,7 @@
 #include "components/discardable_memory/common/discardable_shared_memory_heap.h"
 #include "mojo/public/cpp/bindings/self_owned_receiver.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/files/file_path.h"
 #include "base/files/file_util.h"
 #include "base/metrics/histogram_macros.h"
@@ -176,7 +176,7 @@ int64_t GetDefaultMemoryLimit() {
     max_default_memory_limit /= 8;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::FilePath shmem_dir;
   if (base::GetShmemTempDir(false, &shmem_dir)) {
     int64_t shmem_dir_amount_of_free_space =
