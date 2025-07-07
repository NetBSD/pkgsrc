$NetBSD: patch-base_debug_proc__maps__linux.cc,v 1.3 2025/07/07 09:23:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/proc_maps_linux.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/debug/proc_maps_linux.cc
@@ -22,7 +22,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
