$NetBSD: patch-src_3rdparty_chromium_media_gpu_vaapi_vaapi__wrapper.cc,v 1.1 2025/12/21 09:38:33 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc
@@ -77,7 +77,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
