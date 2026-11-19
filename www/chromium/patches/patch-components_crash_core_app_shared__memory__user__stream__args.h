$NetBSD: patch-components_crash_core_app_shared__memory__user__stream__args.h,v 1.3 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/app/shared_memory_user_stream_args.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/crash/core/app/shared_memory_user_stream_args.h
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||
-                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID),
+                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD),
               "Unsupported platform.");
 
 #include <set>
