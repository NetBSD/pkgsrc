$NetBSD: patch-services_webnn_public_cpp_webnn__sandbox__init.cc,v 1.4 2026/10/02 11:43:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/webnn/public/cpp/webnn_sandbox_init.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ services/webnn/public/cpp/webnn_sandbox_init.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "services/webnn/public/cpp/webnn_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -22,7 +22,7 @@ void PreSandboxWebNNInitialization() {
   base::FilePath library_path(
       FILE_PATH_LITERAL("libLiteRtWebGpuAccelerator.dll"));
   base::LoadNativeLibrary(library_path, nullptr);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath library_path;
   if (base::PathService::Get(base::DIR_MODULE, &library_path)) {
     library_path =
