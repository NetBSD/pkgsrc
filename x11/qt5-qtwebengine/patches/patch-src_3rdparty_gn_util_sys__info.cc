$NetBSD: patch-src_3rdparty_gn_util_sys__info.cc,v 1.1 2023/10/07 20:00:35 adam Exp $

--- src/3rdparty/gn/util/sys_info.cc.orig	2021-08-24 12:21:04.000000000 +0000
+++ src/3rdparty/gn/util/sys_info.cc
@@ -6,12 +6,18 @@
 
 #include "base/logging.h"
 #include "util/build_config.h"
+#include "base/stl_util.h"
 
 #if defined(OS_POSIX)
 #include <sys/utsname.h>
 #include <unistd.h>
 #endif
 
+#if defined(OS_NETBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(OS_WIN)
 #include <windows.h>
 #endif
@@ -24,10 +30,22 @@ std::string OperatingSystemArchitecture(
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
