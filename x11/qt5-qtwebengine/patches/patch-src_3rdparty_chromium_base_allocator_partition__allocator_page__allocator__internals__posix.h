$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_page__allocator__internals__posix.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -24,7 +24,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
