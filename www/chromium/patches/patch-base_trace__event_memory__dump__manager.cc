$NetBSD: patch-base_trace__event_memory__dump__manager.cc,v 1.18 2026/04/21 15:21:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/memory_dump_manager.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ base/trace_event/memory_dump_manager.cc
@@ -96,7 +96,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
