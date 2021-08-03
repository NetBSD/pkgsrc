$NetBSD: patch-src_3rdparty_chromium_chrome_common_media_cdm__host__file__path.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/media/cdm_host_file_path.cc.orig	2020-07-08 21:40:37.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/media/cdm_host_file_path.cc
@@ -95,7 +95,7 @@ void AddCdmHostFilePaths(
   cdm_host_file_paths->emplace_back(chrome_framework_path,
                                     chrome_framework_sig_path);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
   base::FilePath chrome_exe_dir;
   if (!base::PathService::Get(base::DIR_EXE, &chrome_exe_dir))
