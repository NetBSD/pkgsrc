$NetBSD: patch-skia_ext_SkMemory__new__handler.cpp,v 1.20 2026/06/01 10:09:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/SkMemory_new_handler.cpp.orig	2026-05-26 20:39:02.000000000 +0000
+++ skia/ext/SkMemory_new_handler.cpp
@@ -22,7 +22,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -108,7 +108,7 @@ static void* malloc_nothrow(size_t size,
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
