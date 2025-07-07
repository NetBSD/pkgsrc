$NetBSD: patch-base_system_sys__info.h,v 1.3 2025/07/07 09:23:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/system/sys_info.h
@@ -355,6 +355,8 @@ class BASE_EXPORT SysInfo {
   static void ResetCpuSecurityMitigationsEnabledForTesting();
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   friend class test::ScopedAmountOfPhysicalMemoryOverride;
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
@@ -367,7 +369,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static uint64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
