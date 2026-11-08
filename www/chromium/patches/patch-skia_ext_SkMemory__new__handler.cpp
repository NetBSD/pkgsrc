$NetBSD: patch-skia_ext_SkMemory__new__handler.cpp,v 1.32 2026/11/08 15:39:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/SkMemory_new_handler.cpp.orig	2026-11-02 23:22:33.000000000 +0000
+++ skia/ext/SkMemory_new_handler.cpp
@@ -30,7 +30,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -87,7 +87,7 @@ void* sk_realloc_throw(void* addr, size_
       old_size = _msize(addr);
 #elif BUILDFLAG(IS_APPLE)
       old_size = malloc_size(addr);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) && !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_NETBSD)
       old_size = malloc_usable_size(addr);
 #endif
     }
@@ -125,7 +125,7 @@ static void* malloc_nothrow(size_t size,
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
