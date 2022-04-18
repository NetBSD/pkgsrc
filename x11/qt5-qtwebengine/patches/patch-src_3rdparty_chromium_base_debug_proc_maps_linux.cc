$NetBSD: patch-src_3rdparty_chromium_base_debug_proc_maps_linux.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/debug/proc_maps_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/debug/proc_maps_linux.cc
@@ -13,7 +13,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <inttypes.h>
 #endif
 
@@ -29,6 +29,13 @@
 namespace base {
 namespace debug {
 
+#if defined(OS_FREEBSD)
+const char kProcSelfMapsPath[] = "/proc/curproc/map";
+#elif defined(OS_NETBSD)
+const char kProcSelfMapsPath[] = "/proc/self/map";
+#else
+const char kProcSelfMapsPath[] = "/proc/self/map";
+
 // Scans |proc_maps| starting from |pos| returning true if the gate VMA was
 // found, otherwise returns false.
 static bool ContainsGateVMA(std::string* proc_maps, size_t pos) {
@@ -44,15 +51,16 @@ static bool ContainsGateVMA(std::string*
   return false;
 #endif
 }
+#endif
 
 bool ReadProcMaps(std::string* proc_maps) {
   // seq_file only writes out a page-sized amount on each call. Refer to header
   // file for details.
   const long kReadSize = sysconf(_SC_PAGESIZE);
 
-  base::ScopedFD fd(HANDLE_EINTR(open("/proc/self/maps", O_RDONLY)));
+  base::ScopedFD fd(HANDLE_EINTR(open(kProcSelfMapsPath, O_RDONLY)));
   if (!fd.is_valid()) {
-    DPLOG(ERROR) << "Couldn't open /proc/self/maps";
+    DPLOG(ERROR) << "Couldn't open " << kProcSelfMapsPath;
     return false;
   }
   proc_maps->clear();
@@ -66,7 +74,7 @@ bool ReadProcMaps(std::string* proc_maps
 
     ssize_t bytes_read = HANDLE_EINTR(read(fd.get(), buffer, kReadSize));
     if (bytes_read < 0) {
-      DPLOG(ERROR) << "Couldn't read /proc/self/maps";
+      DPLOG(ERROR) << "Couldn't read " << kProcSelfMapsPath;
       proc_maps->clear();
       return false;
     }
@@ -77,6 +85,7 @@ bool ReadProcMaps(std::string* proc_maps
     if (bytes_read == 0)
       break;
 
+#if !defined(OS_BSD)
     // The gate VMA is handled as a special case after seq_file has finished
     // iterating through all entries in the virtual memory table.
     //
@@ -87,6 +96,7 @@ bool ReadProcMaps(std::string* proc_maps
     // Avoid this by searching for the gate VMA and breaking early.
     if (ContainsGateVMA(proc_maps, pos))
       break;
+#endif
   }
 
   return true;
