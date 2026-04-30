$NetBSD: patch-src_3rdparty_chromium_content_browser_service__host_utility__process__host.cc,v 1.1 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/service_host/utility_process_host.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/content/browser/service_host/utility_process_host.cc
@@ -68,7 +68,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -97,7 +97,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -497,7 +497,7 @@ bool UtilityProcessHost::StartProcess() 
       GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The network service should have access to the parent directories
   // necessary for its usage.
   if (options_.sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -515,7 +515,7 @@ bool UtilityProcessHost::StartProcess() 
       video_capture::mojom::VideoCaptureService::Name_) {
     bool pass_gpu_buffer_flag =
         switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Check if NV12 GPU memory buffer supported at the same time.
     pass_gpu_buffer_flag =
         pass_gpu_buffer_flag &&
