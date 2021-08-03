$NetBSD: patch-src_3rdparty_chromium_services_resource__coordinator_memory__instrumentation_queued__request__dispatcher.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/resource_coordinator/memory_instrumentation/queued_request_dispatcher.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/resource_coordinator/memory_instrumentation/queued_request_dispatcher.cc
@@ -43,7 +43,7 @@ namespace {
 uint32_t CalculatePrivateFootprintKb(const mojom::RawOSMemDump& os_dump,
                                      uint32_t shared_resident_kb) {
   DCHECK(os_dump.platform_private_footprint);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   uint64_t rss_anon_bytes = os_dump.platform_private_footprint->rss_anon_bytes;
   uint64_t vm_swap_bytes = os_dump.platform_private_footprint->vm_swap_bytes;
   return (rss_anon_bytes + vm_swap_bytes) / 1024;
@@ -82,7 +82,7 @@ memory_instrumentation::mojom::OSMemDump
   os_dump->is_peak_rss_resettable = internal_os_dump.is_peak_rss_resettable;
   os_dump->private_footprint_kb =
       CalculatePrivateFootprintKb(internal_os_dump, shared_resident_kb);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   os_dump->private_footprint_swap_kb =
       internal_os_dump.platform_private_footprint->vm_swap_bytes / 1024;
 #endif
@@ -243,7 +243,7 @@ void QueuedRequestDispatcher::SetUpAndDi
 
 // On most platforms each process can dump data about their own process
 // so ask each process to do so Linux is special see below.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     request->pending_responses.insert({client_info.pid, ResponseType::kOSDump});
     client->RequestOSMemoryDump(request->memory_map_option(),
                                 {base::kNullProcessId},
