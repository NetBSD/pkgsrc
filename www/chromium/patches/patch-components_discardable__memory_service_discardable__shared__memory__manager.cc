$NetBSD: patch-components_discardable__memory_service_discardable__shared__memory__manager.cc,v 1.18 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -172,7 +172,7 @@ uint64_t GetDefaultMemoryLimit() {
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t max_default_memory_limit = 128 * kMegabyte;
 #else
-  uint64_t max_default_memory_limit = 512 * kMegabyte;
+  uint64_t max_default_memory_limit = 128 * kMegabyte;
 #endif
 
   // Use 1/8th of discardable memory on low-end devices.
