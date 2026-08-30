$NetBSD: patch-Source_ThirdParty_skia_src_ports_SkMemory__malloc.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

webkitgtk-2.46.3/Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp:130:(.text._Z14sk_malloc_sizePvm+0x26): undefined reference to `malloc_usable_size'

--- Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp.orig	2024-11-06 12:45:16.083139292 +0000
+++ Source/ThirdParty/skia/src/ports/SkMemory_malloc.cpp
@@ -126,7 +126,7 @@ size_t sk_malloc_size(void* addr, size_t
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
-    #elif defined(SK_BUILD_FOR_UNIX)
+    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__NetBSD__)
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
     #elif defined(SK_BUILD_FOR_WIN)
