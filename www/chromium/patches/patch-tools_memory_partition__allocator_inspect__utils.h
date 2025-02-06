$NetBSD: patch-tools_memory_partition__allocator_inspect__utils.h,v 1.1 2025/02/06 09:58:30 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/memory/partition_allocator/inspect_utils.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ tools/memory/partition_allocator/inspect_utils.h
@@ -61,7 +61,7 @@ class RemoteProcessMemoryReader {
   const pid_t pid_;
   bool is_valid_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedFD mem_fd_;
 #elif BUILDFLAG(IS_MAC)
   task_t task_;
