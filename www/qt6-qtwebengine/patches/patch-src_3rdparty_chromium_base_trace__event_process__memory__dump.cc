$NetBSD: patch-src_3rdparty_chromium_base_trace__event_process__memory__dump.cc,v 1.1 2025/12/21 09:38:17 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/trace_event/process_memory_dump.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/base/trace_event/process_memory_dump.cc
@@ -143,7 +143,7 @@ std::optional<size_t> ProcessMemoryDump:
     for (size_t i = 0; i < page_count; i++) {
       resident_page_count += vec[i].VirtualAttributes.Valid;
     }
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050620): Implement counting resident bytes.
     // For now, log and avoid unused variable warnings.
     NOTIMPLEMENTED_LOG_ONCE();
