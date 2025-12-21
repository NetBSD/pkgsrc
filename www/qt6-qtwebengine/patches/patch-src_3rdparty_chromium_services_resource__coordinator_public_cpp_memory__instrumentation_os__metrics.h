$NetBSD: patch-src_3rdparty_chromium_services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics.h,v 1.1 2025/12/21 09:38:38 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -57,7 +57,7 @@ class COMPONENT_EXPORT(
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(
       base::ProcessHandle);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   static void SetProcSmapsForTesting(FILE*);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
@@ -79,7 +79,7 @@ class COMPONENT_EXPORT(
   GetMemoryInfo(base::ProcessHandle handle);
 #endif  // !BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Provides information on the dump state of resident pages. These values are
   // written to logs. New enum values can be added, but existing enums must
   // never be renumbered or deleted and reused.
