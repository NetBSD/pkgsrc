$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.2 2025/05/16 16:08:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -81,7 +81,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
