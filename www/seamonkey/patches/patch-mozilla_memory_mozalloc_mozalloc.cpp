$NetBSD: patch-mozilla_memory_mozalloc_mozalloc.cpp,v 1.1.2.2 2012/07/21 19:58:38 tron Exp $

* Fix build on NetBSD with mozilla-jemalloc option (functionality is not tested)

--- mozilla/memory/mozalloc/mozalloc.cpp.orig	2012-07-15 12:00:39.000000000 +0000
+++ mozilla/memory/mozalloc/mozalloc.cpp
@@ -243,7 +243,7 @@ moz_malloc_usable_size(void *ptr)
 
 #if defined(XP_MACOSX)
     return malloc_size(ptr);
-#elif defined(MOZ_MEMORY) || (defined(XP_LINUX) && !defined(ANDROID))
+#elif (defined(MOZ_MEMORY) && !defined(__NetBSD__)) || (defined(XP_LINUX) && !defined(ANDROID))
     // Android bionic libc doesn't have malloc_usable_size.
     return malloc_usable_size(ptr);
 #elif defined(XP_WIN)
