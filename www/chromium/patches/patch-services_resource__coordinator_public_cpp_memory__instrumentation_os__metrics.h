$NetBSD: patch-services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics.h,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -53,7 +53,7 @@ class COMPONENT_EXPORT(
                                     mojom::RawOSMemDump*);
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(base::ProcessId);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   static void SetProcSmapsForTesting(FILE*);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
@@ -70,7 +70,7 @@ class COMPONENT_EXPORT(
   static std::vector<mojom::VmRegionPtr> GetProcessModules(base::ProcessId);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Provides information on the dump state of resident pages. These values are
   // written to logs. New enum values can be added, but existing enums must
   // never be renumbered or deleted and reused.
