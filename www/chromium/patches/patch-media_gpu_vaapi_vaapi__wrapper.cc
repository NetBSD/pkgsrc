$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.12 2025/12/13 14:53:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -84,7 +84,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
