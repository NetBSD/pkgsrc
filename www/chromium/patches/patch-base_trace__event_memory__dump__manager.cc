$NetBSD: patch-base_trace__event_memory__dump__manager.cc,v 1.15 2026/02/15 09:03:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/memory_dump_manager.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -84,7 +84,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
