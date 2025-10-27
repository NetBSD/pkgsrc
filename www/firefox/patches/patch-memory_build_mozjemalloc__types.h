$NetBSD: patch-memory_build_mozjemalloc__types.h,v 1.1 2025/10/27 14:24:33 ryoon Exp $

* Try to fix build with mozilla-jemalloc option.

--- memory/build/mozjemalloc_types.h.orig	2025-10-09 16:40:29.000000000 +0000
+++ memory/build/mozjemalloc_types.h
@@ -50,11 +50,13 @@
 extern "C" {
 #endif
 
-#ifndef MALLOC_USABLE_SIZE_CONST_PTR
-#  define MALLOC_USABLE_SIZE_CONST_PTR const
+#ifdef MALLOC_USABLE_SIZE_CONST_PTR
+#  define MALLOC_USABLE_SIZE_CONST_PTR_CONST const
+#else
+#  define MALLOC_USABLE_SIZE_CONST_PTR_CONST
 #endif
 
-typedef MALLOC_USABLE_SIZE_CONST_PTR void* usable_ptr_t;
+typedef MALLOC_USABLE_SIZE_CONST_PTR_CONST void* usable_ptr_t;
 
 typedef size_t arena_id_t;
 
