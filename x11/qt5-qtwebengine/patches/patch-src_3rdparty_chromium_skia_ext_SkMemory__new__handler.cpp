$NetBSD: patch-src_3rdparty_chromium_skia_ext_SkMemory__new__handler.cpp,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp
@@ -78,7 +78,7 @@ static void* malloc_nothrow(size_t size)
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
@@ -98,7 +98,7 @@ static void* calloc_nothrow(size_t size)
   // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = calloc(1, size);
 #else
     // It's the responsibility of the caller to check the return value.
