$NetBSD: patch-components_crash_core_app_shared__memory__user__stream__args.cc,v 1.3 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/app/shared_memory_user_stream_args.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/crash/core/app/shared_memory_user_stream_args.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||
-                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID),
+                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD),
               "Unsupported platform.");
 
 #include <stdint.h>
