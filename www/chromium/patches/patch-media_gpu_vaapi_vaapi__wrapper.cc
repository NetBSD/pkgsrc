$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.8 2025/10/16 19:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -85,7 +85,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
