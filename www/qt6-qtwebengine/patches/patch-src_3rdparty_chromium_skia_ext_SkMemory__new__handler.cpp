$NetBSD: patch-src_3rdparty_chromium_skia_ext_SkMemory__new__handler.cpp,v 1.2 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/skia/ext/SkMemory_new_handler.cpp
@@ -24,7 +24,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -110,7 +110,7 @@ static void* malloc_nothrow(size_t size,
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
