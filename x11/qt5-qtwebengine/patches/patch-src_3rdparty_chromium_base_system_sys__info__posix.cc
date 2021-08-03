$NetBSD: patch-src_3rdparty_chromium_base_system_sys__info__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/system/sys_info_posix.cc.orig	2020-07-15 18:55:48.000000000 +0000
+++ src/3rdparty/chromium/base/system/sys_info_posix.cc
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -127,7 +127,7 @@ bool GetDiskSpaceInfo(const base::FilePa
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
@@ -220,6 +220,8 @@ std::string SysInfo::OperatingSystemArch
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
