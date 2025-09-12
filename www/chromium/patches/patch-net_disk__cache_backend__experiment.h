$NetBSD: patch-net_disk__cache_backend__experiment.h,v 1.7 2025/09/12 16:02:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/disk_cache/backend_experiment.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ net/disk_cache/backend_experiment.h
@@ -15,7 +15,7 @@ namespace disk_cache {
 // default.
 constexpr bool IsSimpleBackendEnabledByDefaultPlatform() {
   return BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) ||
-         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC);
+         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD);
 }
 
 // True if assigned to any of disk cache backend experiment groups.
