$NetBSD: patch-base_trace__event_process__memory__dump.cc,v 1.3 2025/07/07 09:23:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/process_memory_dump.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/trace_event/process_memory_dump.cc
@@ -119,7 +119,7 @@ std::optional<size_t> ProcessMemoryDump:
 #if BUILDFLAG(IS_WIN)
   auto vec =
       base::HeapArray<PSAPI_WORKING_SET_EX_INFORMATION>::WithSize(max_vec_size);
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   auto vec = base::HeapArray<char>::WithSize(max_vec_size);
 #elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
   auto vec = base::HeapArray<unsigned char>::WithSize(max_vec_size);
@@ -143,7 +143,7 @@ std::optional<size_t> ProcessMemoryDump:
     for (size_t i = 0; i < page_count; i++) {
       resident_page_count += vec[i].VirtualAttributes.Valid;
     }
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050620): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
