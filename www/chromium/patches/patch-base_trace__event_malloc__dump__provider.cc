$NetBSD: patch-base_trace__event_malloc__dump__provider.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/malloc_dump_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/trace_event/malloc_dump_provider.cc
@@ -28,6 +28,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -178,7 +180,7 @@ void ReportAppleAllocStats(size_t* total
 
 #if (PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(IS_ANDROID)) || \
     (!PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && !BUILDFLAG(IS_WIN) &&    \
-     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA))
+     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD))
 void ReportMallinfoStats(ProcessMemoryDump* pmd,
                          size_t* total_virtual_size,
                          size_t* resident_size,
@@ -368,6 +370,9 @@ bool MallocDumpProvider::OnMemoryDump(co
                      &allocated_objects_count);
 #elif BUILDFLAG(IS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif BUILDFLAG(IS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   ReportMallinfoStats(/*pmd=*/nullptr, &total_virtual_size, &resident_size,
                       &allocated_objects_size, &allocated_objects_count);
