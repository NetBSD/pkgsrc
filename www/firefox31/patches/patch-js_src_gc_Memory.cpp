$NetBSD: patch-js_src_gc_Memory.cpp,v 1.2 2015/05/26 12:18:23 ryoon Exp $

Make sure mmap() delivers memory with upper 17 bits clear on sparc64 on NetBSD:
with topdown-vm we would map in the last 4 gig of the address space (past
the VA hole) otherwise by default, thus busting the JSValue restrictions.

https://bugzilla.mozilla.org/show_bug.cgi?id=994133


--- js/src/gc/Memory.cpp.orig	2015-05-05 02:53:53.000000000 +0000
+++ js/src/gc/Memory.cpp
@@ -212,7 +212,7 @@ gc::InitMemorySubsystem(JSRuntime* rt)
 static inline void*
 MapMemory(size_t length, int prot, int flags, int fd, off_t offset)
 {
-#if defined(__ia64__)
+#if defined(__ia64__) || (defined(__sparc64__) && defined(__NetBSD__))
     /*
      * The JS engine assumes that all allocated pointers have their high 17 bits clear,
      * which ia64's mmap doesn't support directly. However, we can emulate it by passing
