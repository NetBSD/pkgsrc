$NetBSD: patch-base_trace__event_memory__dump__manager.cc,v 1.8 2025/10/16 19:43:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/trace_event/memory_dump_manager.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ base/trace_event/memory_dump_manager.cc
@@ -78,7 +78,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
