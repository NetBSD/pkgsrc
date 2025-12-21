$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_instrumentation_partition__alloc__memory__dump__provider.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc
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
@@ -49,6 +52,7 @@ bool PartitionAllocMemoryDumpProvider::O
       "size", "bytes", partition_stats_dumper.total_active_bytes());
   memory_dump->AddOwnershipEdge(allocated_objects_dump->guid(),
                                 partitions_dump->guid());
+#endif
 
   return true;
 }
