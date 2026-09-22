$NetBSD: patch-base_trace__event_process__memory__dump.cc,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/process_memory_dump.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ base/trace_event/process_memory_dump.cc
@@ -43,7 +43,7 @@
 #include <Psapi.h>
 #endif
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include <tuple>
 
 #include "base/notreached.h"
@@ -119,7 +119,7 @@ std::optional<size_t> ProcessMemoryDump:
 #if BUILDFLAG(IS_WIN)
   auto vec = base::HeapArray<PSAPI_WORKING_SET_EX_INFORMATION>::WithSize(
       max_page_count);
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   auto vec = base::HeapArray<char>::WithSize(max_page_count);
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
   auto vec = base::HeapArray<unsigned char>::WithSize(max_page_count);
@@ -161,7 +161,7 @@ std::optional<size_t> ProcessMemoryDump:
     for (size_t i = 0; i < page_count; i++) {
       accumulate_page_if_resident(i, vec[i].VirtualAttributes.Valid);
     }
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050620): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
