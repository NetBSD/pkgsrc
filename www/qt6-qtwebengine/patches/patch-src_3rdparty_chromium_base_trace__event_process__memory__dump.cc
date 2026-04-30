$NetBSD: patch-src_3rdparty_chromium_base_trace__event_process__memory__dump.cc,v 1.2 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/trace_event/process_memory_dump.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/base/trace_event/process_memory_dump.cc
@@ -47,7 +47,7 @@
 #include <Psapi.h>
 #endif
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include <tuple>
 
 #include "base/notreached.h"
@@ -116,7 +116,7 @@ std::optional<size_t> ProcessMemoryDump:
 #if BUILDFLAG(IS_WIN)
   auto vec =
       base::HeapArray<PSAPI_WORKING_SET_EX_INFORMATION>::WithSize(max_vec_size);
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   auto vec = base::HeapArray<char>::WithSize(max_vec_size);
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
   auto vec = base::HeapArray<unsigned char>::WithSize(max_vec_size);
@@ -140,7 +140,7 @@ std::optional<size_t> ProcessMemoryDump:
     for (size_t i = 0; i < page_count; i++) {
       resident_page_count += vec[i].VirtualAttributes.Valid;
     }
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050620): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
