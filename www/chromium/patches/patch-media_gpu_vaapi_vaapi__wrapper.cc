$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.18 2026/04/21 15:21:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -79,7 +79,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
