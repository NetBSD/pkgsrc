$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -77,7 +77,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
