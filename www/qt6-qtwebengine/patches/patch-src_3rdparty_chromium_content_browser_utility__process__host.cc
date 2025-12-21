$NetBSD: patch-src_3rdparty_chromium_content_browser_utility__process__host.cc,v 1.1 2025/12/21 09:38:27 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/utility_process_host.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/content/browser/utility_process_host.cc
@@ -63,7 +63,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -91,7 +91,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -321,7 +321,7 @@ bool UtilityProcessHost::StartProcess() 
         network::switches::kTestThirdPartyCookiePhaseout,
         network::switches::kDisableSharedDictionaryStorageCleanupForTesting,
         sandbox::policy::switches::kNoSandbox,
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
         switches::kDisableDevShmUsage,
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -353,7 +353,7 @@ bool UtilityProcessHost::StartProcess() 
         switches::kMuteAudio,
         switches::kUseFileForFakeAudioCapture,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
         switches::kAlsaInputDevice,
         switches::kAlsaOutputDevice,
 #endif
@@ -416,7 +416,7 @@ bool UtilityProcessHost::StartProcess() 
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload(*cmd_line));
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -433,7 +433,7 @@ bool UtilityProcessHost::StartProcess() 
     if (metrics_name_ == video_capture::mojom::VideoCaptureService::Name_) {
       bool pass_gpu_buffer_flag =
           switches::IsVideoCaptureUseGpuMemoryBufferEnabled();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if NV12 GPU memory buffer supported at the same time.
       pass_gpu_buffer_flag =
           pass_gpu_buffer_flag &&
