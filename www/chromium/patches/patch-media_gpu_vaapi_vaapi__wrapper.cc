$NetBSD: patch-media_gpu_vaapi_vaapi__wrapper.cc,v 1.16 2026/03/14 12:40:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -79,7 +79,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
