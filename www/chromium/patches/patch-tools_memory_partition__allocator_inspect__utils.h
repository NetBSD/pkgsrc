$NetBSD: patch-tools_memory_partition__allocator_inspect__utils.h,v 1.24 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/memory/partition_allocator/inspect_utils.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ tools/memory/partition_allocator/inspect_utils.h
@@ -61,7 +61,7 @@ class RemoteProcessMemoryReader {
   const pid_t pid_;
   bool is_valid_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedFD mem_fd_;
 #elif BUILDFLAG(IS_MAC)
   task_t task_;
