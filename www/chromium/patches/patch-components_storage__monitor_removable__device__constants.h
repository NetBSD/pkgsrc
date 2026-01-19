$NetBSD: patch-components_storage__monitor_removable__device__constants.h,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/storage_monitor/removable_device_constants.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/storage_monitor/removable_device_constants.h
@@ -15,7 +15,7 @@ namespace storage_monitor {
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const char kFSUniqueIdPrefix[];
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const char kVendorModelSerialPrefix[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const
     char kVendorModelVolumeStoragePrefix[];
 #endif
