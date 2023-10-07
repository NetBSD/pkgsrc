$NetBSD: patch-src_3rdparty_chromium_base_system_sys__info__posix.cc,v 1.2 2023/10/07 20:00:35 adam Exp $

--- src/3rdparty/chromium/base/system/sys_info_posix.cc.orig	2022-09-19 14:36:40.000000000 +0000
+++ src/3rdparty/chromium/base/system/sys_info_posix.cc
@@ -22,6 +22,10 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 
+#if defined(OS_NETBSD)
+#include <sys/sysctl.h>
+#endif
+
 #if defined(OS_ANDROID)
 #include <sys/vfs.h>
 #define statvfs statfs  // Android uses a statvfs-like statfs struct and call.
@@ -36,7 +40,7 @@
 
 namespace {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int NumberOfProcessors() {
   // sysconf returns the number of "logical" (not "physical") processors on both
   // Mac and Linux.  So we get the number of max available "logical" processors.
@@ -128,7 +132,7 @@ bool GetDiskSpaceInfo(const base::FilePa
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
@@ -219,10 +223,22 @@ std::string SysInfo::OperatingSystemArch
     return std::string();
   }
   std::string arch(info.machine);
+#if defined(OS_NETBSD)
+  int mib[] = {CTL_HW, HW_MACHINE_ARCH};
+  char name[32];
+  size_t len = base::size(name);
+  if (sysctl(mib, base::size(mib), name, &len, NULL, 0) < 0) {
+    NOTREACHED();
+    return std::string();
+  }
+  arch = name;
+#endif // defined(OS_NETBSD)
   if (arch == "i386" || arch == "i486" || arch == "i586" || arch == "i686") {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
