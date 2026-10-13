$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.29 2026/10/13 13:16:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -83,7 +83,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
