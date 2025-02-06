$NetBSD: patch-v8_src_base_platform_platform-freebsd.cc,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/platform/platform-freebsd.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/base/platform/platform-freebsd.cc
@@ -43,14 +43,10 @@ TimezoneCache* OS::CreateTimezoneCache()
   return new PosixDefaultTimezoneCache();
 }
 
-static unsigned StringToLong(char* buffer) {
-  return static_cast<unsigned>(strtol(buffer, nullptr, 16));
-}
-
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
   std::vector<SharedLibraryAddress> result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
-  size_t miblen = sizeof(mib) / sizeof(mib[0]);
+  unsigned int miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
   if (sysctl(mib, miblen, nullptr, &buffer_size, nullptr, 0) == 0) {
     // Overallocate the buffer by 1/3 to account for concurrent
@@ -82,8 +78,13 @@ std::vector<OS::SharedLibraryAddress> OS
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
+#if defined(__i386__) || defined(OS_FREEBSD)
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
+#else
               lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
               reinterpret_cast<uintptr_t>(map->kve_end)));
+#endif
         }
 
         start += ssize;
