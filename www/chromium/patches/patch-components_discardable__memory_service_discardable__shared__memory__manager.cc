$NetBSD: patch-components_discardable__memory_service_discardable__shared__memory__manager.cc,v 1.25 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -178,6 +178,8 @@ uint64_t GetDefaultMaxBytes() {
 #if BUILDFLAG(IS_ANDROID)
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t default_max_bytes = 128 * kMegabyte;
+#elif BUILDFLAG(IS_OPENBSD)
+  uint64_t default_max_bytes = 128 * kMegabyte;
 #else
   uint64_t default_max_bytes = 512 * kMegabyte;
 #endif
