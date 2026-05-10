$NetBSD: patch-base_system_sys__info__freebsd.cc,v 1.19 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info_freebsd.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ base/system/sys_info_freebsd.cc
@@ -10,20 +10,74 @@
 
 #include "base/notreached.h"
 #include "base/numerics/safe_conversions.h"
+#include "base/process/process_metrics.h"
+#include "base/strings/string_util.h"
 
 namespace base {
 
+int SysInfo::NumberOfProcessors() {
+  int mib[] = {CTL_HW, HW_NCPU};
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
+    NOTREACHED();
+    return 1;
+  }
+  return ncpu;
+}
+
 ByteSize SysInfo::AmountOfTotalPhysicalMemoryImpl() {
-  int pages, page_size;
+  int pages, page_size, r = 0;
   size_t size = sizeof(pages);
-  sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
-  sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
-  if (pages == -1 || page_size == -1) {
+
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_count", &pages, &size, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+
+  if (r == -1) {
     NOTREACHED();
   }
+
   return ByteSize(checked_cast<unsigned>(page_size)) * pages;
 }
 
+ByteSize SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
+  int page_size, r = 0;
+  unsigned int pgfree, pginact, pgcache;
+  size_t size = sizeof(page_size);
+  size_t szpg = sizeof(pgfree);
+
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_free_count", &pgfree, &szpg, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_inactive_count", &pginact, &szpg, NULL, 0);
+  if (r == 0)
+    r = sysctlbyname("vm.stats.vm.v_cache_count", &pgcache, &szpg, NULL, 0);
+
+  if (r == -1) {
+    NOTREACHED();
+    return ByteSize(0);
+  }
+
+  return ByteSize((pgfree + pginact + pgcache) * checked_cast<unsigned>(page_size));
+}
+
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t size = std::size(name);
+
+  if (sysctl(mib, std::size(mib), &name, &size, NULL, 0) == 0) {
+    return name;
+  }
+
+  return std::string();
+}
+
 // static
 uint64_t SysInfo::MaxSharedMemorySize() {
   size_t limit;
@@ -34,4 +88,16 @@ uint64_t SysInfo::MaxSharedMemorySize() 
   return static_cast<uint64_t>(limit);
 }
 
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+
+  info.manufacturer = "FreeBSD";
+  info.model = HardwareModelName();
+
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+
+  return info;
+}
+
 }  // namespace base
