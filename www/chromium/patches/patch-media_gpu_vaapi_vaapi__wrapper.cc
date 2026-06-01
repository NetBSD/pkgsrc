$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.20 2026/06/01 10:09:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -80,7 +80,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
