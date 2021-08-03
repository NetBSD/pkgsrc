$NetBSD: patch-src_3rdparty_chromium_base_debug_stack__trace__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/debug/stack_trace_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/debug/stack_trace_posix.cc
@@ -35,7 +35,7 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/debug/proc_maps_linux.h"
 #endif
 
@@ -657,6 +657,9 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_BSD)
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -674,6 +677,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
@@ -697,7 +701,11 @@ class SandboxSymbolizeHelper {
           // Skip regions with empty file names.
           continue;
         }
+#if defined(OS_BSD)
         if (region.path[0] == '[') {
+#else
+        if (region.path[0] == '[') {
+#endif
           // Skip pseudo-paths, like [stack], [vdso], [heap], etc ...
           continue;
         }
