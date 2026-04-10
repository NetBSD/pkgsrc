$NetBSD: patch-base_system_sys__info__posix.cc,v 1.17 2026/04/10 17:31:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info_posix.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/system/sys_info_posix.cc
@@ -58,7 +58,11 @@ base::ByteSize AmountOfVirtualMemory() {
   if (result != 0) {
     NOTREACHED();
   }
+#if BUILDFLAG(IS_FREEBSD)
+  return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : base::checked_cast<uint64_t>(limit.rlim_cur));
+#else
   return base::ByteSize(limit.rlim_cur == RLIM_INFINITY ? 0 : limit.rlim_cur);
+#endif
 }
 using LazyVirtualMemory =
     base::internal::LazySysInfoValue<base::ByteSize, AmountOfVirtualMemory>;
@@ -140,7 +144,7 @@ void GetKernelVersionNumbers(int32_t* ma
 
 namespace base {
 
-#if !BUILDFLAG(IS_OPENBSD)
+#if !BUILDFLAG(IS_BSD)
 // static
 int SysInfo::NumberOfProcessors() {
 #if BUILDFLAG(IS_MAC)
@@ -196,7 +200,7 @@ int SysInfo::NumberOfProcessors() {
 
   return cached_num_cpus;
 }
-#endif  // !BUILDFLAG(IS_OPENBSD)
+#endif  // !BUILDFLAG(IS_BSD)
 
 // static
 ByteSize SysInfo::AmountOfVirtualMemory() {
@@ -286,6 +290,8 @@ std::string SysInfo::OperatingSystemArch
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
