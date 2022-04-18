$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_page__allocator__internals__posix.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -24,7 +24,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
