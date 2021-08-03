$NetBSD: patch-src_3rdparty_chromium_base_process_memory.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/memory.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/memory.cc
@@ -44,7 +44,7 @@ NOINLINE void OnNoMemoryInternal(size_t 
 }  // namespace internal
 
 // Defined in memory_win.cc for Windows.
-#if !defined(OS_WIN)
+#if !defined(OS_WIN) && !defined(OS_BSD)
 
 namespace {
 
@@ -63,7 +63,7 @@ void TerminateBecauseOutOfMemory(size_t 
 #endif  // !defined(OS_WIN)
 
 // Defined in memory_mac.mm for Mac.
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
   const size_t alloc_size = num_items * size;
