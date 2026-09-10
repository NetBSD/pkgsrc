$NetBSD: patch-src_modules_memory_bsd.cpp,v 1.1 2026/09/10 09:15:32 kikadf Exp $

* Fix get_free_memory on NetBSD, avoid underflow
https://github.com/Alexays/Waybar/pull/5319

--- src/modules/memory/bsd.cpp.orig	2026-09-09 17:46:47.416277348 +0000
+++ src/modules/memory/bsd.cpp
@@ -73,10 +73,16 @@ static uint64_t get_free_memory() {
   if (sysctl(mib, miblen, &uvmexp, &sz, NULL, 0)) {
     throw std::runtime_error("sysctl vm.uvmexp failed");
   }
+#ifdef VM_UVMEXP2
+  uint64_t total = get_total_memory();
+  uint64_t used = static_cast<uint64_t>(uvmexp.active + uvmexp.wired) * uvmexp.pagesize;
+  return used < total ? total - used : 0;
+#else
   return static_cast<uint64_t>(uvmexp.free + uvmexp.inactive + uvmexp.filepages +
                                uvmexp.execpages) *
          uvmexp.pagesize;
 #endif
+#endif
 }
 
 void waybar::modules::Memory::parseMeminfo() {
