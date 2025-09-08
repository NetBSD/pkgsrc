$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -83,7 +83,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
