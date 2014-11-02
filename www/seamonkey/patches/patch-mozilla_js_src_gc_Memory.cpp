$NetBSD: patch-mozilla_js_src_gc_Memory.cpp,v 1.4 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/js/src/gc/Memory.cpp.orig	2014-10-14 06:36:16.000000000 +0000
+++ mozilla/js/src/gc/Memory.cpp
@@ -406,7 +406,7 @@ static inline void *
 MapMemory(size_t length, int prot = PROT_READ | PROT_WRITE,
           int flags = MAP_PRIVATE | MAP_ANON, int fd = -1, off_t offset = 0)
 {
-#if defined(__ia64__)
+#if defined(__ia64__) || (defined(__sparc64__) && defined(__NetBSD__))
     /*
      * The JS engine assumes that all allocated pointers have their high 17 bits clear,
      * which ia64's mmap doesn't support directly. However, we can emulate it by passing
