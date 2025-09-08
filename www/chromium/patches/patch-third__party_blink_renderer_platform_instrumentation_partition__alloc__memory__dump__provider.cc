$NetBSD: patch-third__party_blink_renderer_platform_instrumentation_partition__alloc__memory__dump__provider.cc,v 1.6 2025/09/08 13:24:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc
@@ -14,7 +14,9 @@
 
 namespace blink {
 
+#if !BUILDFLAG(IS_BSD)
 const char kPartitionAllocDumpName[] = "partition_alloc";
+#endif
 
 PartitionAllocMemoryDumpProvider* PartitionAllocMemoryDumpProvider::Instance() {
   DEFINE_STATIC_LOCAL(PartitionAllocMemoryDumpProvider, instance, ());
@@ -24,6 +26,7 @@ PartitionAllocMemoryDumpProvider* Partit
 bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
     const base::trace_event::MemoryDumpArgs& args,
     base::trace_event::ProcessMemoryDump* memory_dump) {
+#if !BUILDFLAG(IS_BSD)
   using base::trace_event::MemoryDumpLevelOfDetail;
 
   MemoryDumpLevelOfDetail level_of_detail = args.level_of_detail;
@@ -48,6 +51,7 @@ bool PartitionAllocMemoryDumpProvider::O
       "size", "bytes", partition_stats_dumper.total_active_bytes());
   memory_dump->AddOwnershipEdge(allocated_objects_dump->guid(),
                                 partitions_dump->guid());
+#endif
 
   return true;
 }
