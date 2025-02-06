$NetBSD: patch-third__party_skia_src_ports_SkMemory__malloc.cpp,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/src/ports/SkMemory_malloc.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/skia/src/ports/SkMemory_malloc.cpp
@@ -15,7 +15,8 @@
 
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
-#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__) && \
+    !defined(__NetBSD__)
 #include <malloc.h>
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
@@ -126,7 +127,7 @@ size_t sk_malloc_size(void* addr, size_t
     #elif defined(SK_BUILD_FOR_ANDROID) && __ANDROID_API__ >= 17
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
-    #elif defined(SK_BUILD_FOR_UNIX)
+    #elif defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__) && !defined(__NetBSD__)
         completeSize = malloc_usable_size(addr);
         SkASSERT(completeSize >= size);
     #elif defined(SK_BUILD_FOR_WIN)
