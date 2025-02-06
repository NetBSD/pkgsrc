$NetBSD: patch-media_gpu_test_raw__video.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/raw_video.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/gpu/test/raw_video.cc
@@ -60,7 +60,7 @@ std::unique_ptr<base::MemoryMappedFile> 
                              base::File::FLAG_READ | base::File::FLAG_WRITE
 // On Windows FLAG_CREATE_ALWAYS will require FLAG_WRITE, and FLAG_APPEND
 // must not be specified.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                              | base::File::FLAG_APPEND
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
           ),
