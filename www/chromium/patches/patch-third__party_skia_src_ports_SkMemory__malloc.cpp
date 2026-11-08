$NetBSD: patch-third__party_skia_src_ports_SkMemory__malloc.cpp,v 1.32 2026/11/08 15:39:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/src/ports/SkMemory_malloc.cpp.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/skia/src/ports/SkMemory_malloc.cpp
@@ -17,7 +17,8 @@
 
 #if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
 #include <malloc/malloc.h>
-#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX)
+#elif defined(SK_BUILD_FOR_ANDROID) || defined(SK_BUILD_FOR_UNIX) && !defined(__OpenBSD__) && \
+    !defined(__NetBSD__)
 #include <malloc.h>
 #elif defined(SK_BUILD_FOR_WIN)
 #include <malloc.h>
