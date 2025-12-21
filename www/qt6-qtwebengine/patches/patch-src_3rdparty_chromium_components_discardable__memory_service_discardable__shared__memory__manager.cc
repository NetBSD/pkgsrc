$NetBSD: patch-src_3rdparty_chromium_components_discardable__memory_service_discardable__shared__memory__manager.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -172,7 +172,7 @@ uint64_t GetDefaultMemoryLimit() {
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t max_default_memory_limit = 128 * kMegabyte;
 #else
-  uint64_t max_default_memory_limit = 512 * kMegabyte;
+  uint64_t max_default_memory_limit = 128 * kMegabyte;
 #endif
 
   // Use 1/8th of discardable memory on low-end devices.
