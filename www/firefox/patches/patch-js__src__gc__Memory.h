$NetBSD: patch-js__src__gc__Memory.h,v 1.2 2013/06/26 11:32:12 ryoon Exp $

From bugzilla, bug 840242, attachment v1
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


diff js/src/gc/Memory.h js/src/gc/Memory.h
--- js/src/gc/Memory.h.orig	2013-06-17 22:13:09.000000000 +0000
+++ js/src/gc/Memory.h
@@ -16,23 +16,34 @@ namespace gc {
 
 // Sanity check that our compiled configuration matches the currently running
 // instance and initialize any runtime data needed for allocation.
-void InitMemorySubsystem();
+void
+InitMemorySubsystem(JSRuntime *rt);
+
+// Decommiting unused memory requires the arena size match the page size.
+bool
+DecommitEnabled(JSRuntime *rt);
 
 // Allocate or deallocate pages from the system with the given alignment.
-void *MapAlignedPages(size_t size, size_t alignment);
-void UnmapPages(void *p, size_t size);
+void *
+MapAlignedPages(JSRuntime *rt, size_t size, size_t alignment);
+
+void
+UnmapPages(JSRuntime *rt, void *p, size_t size);
 
 // Tell the OS that the given pages are not in use, so they should not
 // be written to a paging file. This may be a no-op on some platforms.
-bool MarkPagesUnused(void *p, size_t size);
+bool
+MarkPagesUnused(JSRuntime *rt, void *p, size_t size);
 
 // Undo |MarkPagesUnused|: tell the OS that the given pages are of interest
 // and should be paged in and out normally. This may be a no-op on some
 // platforms.
-bool MarkPagesInUse(void *p, size_t size);
+bool
+MarkPagesInUse(JSRuntime *rt, void *p, size_t size);
 
 // Returns #(hard faults) + #(soft faults)
-size_t GetPageFaultCount();
+size_t
+GetPageFaultCount();
 
 } // namespace gc
 } // namespace js
