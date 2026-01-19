$NetBSD: patch-base_system_sys__info__posix.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/system/sys_info_posix.cc
@@ -143,7 +143,7 @@ void GetKernelVersionNumbers(int32_t* ma
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 // static
 int SysInfo::NumberOfProcessors() {
 #if BUILDFLAG(IS_MAC)
@@ -199,7 +199,7 @@ int SysInfo::NumberOfProcessors() {
 
   return cached_num_cpus;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 ByteCount SysInfo::AmountOfVirtualMemory() {
@@ -289,6 +289,8 @@ std::string SysInfo::OperatingSystemArch
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
