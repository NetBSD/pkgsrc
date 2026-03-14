$NetBSD: patch-base_trace__event_memory__dump__manager.cc,v 1.16 2026/03/14 12:40:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/memory_dump_manager.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -95,7 +95,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
