$NetBSD: patch-net_disk__cache_backend__experiment.h,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/disk_cache/backend_experiment.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ net/disk_cache/backend_experiment.h
@@ -15,7 +15,7 @@ namespace disk_cache {
 // default.
 constexpr bool IsSimpleBackendEnabledByDefaultPlatform() {
   return BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) ||
-         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC);
+         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD);
 }
 
 // True if assigned to any of disk cache backend experiment groups.
