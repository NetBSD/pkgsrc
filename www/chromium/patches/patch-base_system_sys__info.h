$NetBSD: patch-base_system_sys__info.h,v 1.12 2025/12/13 14:53:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ base/system/sys_info.h
@@ -354,6 +354,8 @@ class BASE_EXPORT SysInfo {
   static void ResetCpuSecurityMitigationsEnabledForTesting();
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   friend class test::ScopedAmountOfPhysicalMemoryOverride;
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
@@ -366,7 +368,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static ByteCount AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfo& meminfo);
 #endif
