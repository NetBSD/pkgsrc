$NetBSD: patch-js_src_gc_Memory.cpp,v 1.5 2019/01/29 16:28:22 ryoon Exp $

Support SunOS/x86_64.

--- js/src/gc/Memory.cpp.orig	2019-01-18 00:20:30.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -487,6 +487,7 @@ static inline void* MapMemoryAt(void* de
                                 off_t offset = 0) {
 
 #if defined(__ia64__) || defined(__aarch64__) ||  \
+    (defined(__sun) && defined(__x86_64__)) || \
     (defined(__sparc__) && defined(__arch64__) && \
      (defined(__NetBSD__) || defined(__linux__)))
   MOZ_ASSERT((0xffff800000000000ULL & (uintptr_t(desired) + length - 1)) == 0);
@@ -544,7 +545,7 @@ static inline void* MapMemory(size_t len
   }
   return region;
 #elif defined(__aarch64__) || \
-    (defined(__sparc__) && defined(__arch64__) && defined(__linux__))
+    (defined(__sparc__) && defined(__arch64__) && defined(__linux__)) || (defined(__sun) && defined(__x86_64__))
   /*
    * There might be similar virtual address issue on arm64 which depends on
    * hardware and kernel configurations. But the work around is slightly
