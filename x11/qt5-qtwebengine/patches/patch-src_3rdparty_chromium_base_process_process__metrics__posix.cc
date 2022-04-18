$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics__posix.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_metrics_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_metrics_posix.cc
@@ -20,6 +20,7 @@
 
 #if defined(OS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
 #else
 #include <malloc.h>
 #endif
@@ -126,7 +127,7 @@ size_t ProcessMetrics::GetMallocUsage() 
 #else
   return minfo.hblkhd + minfo.arena;
 #endif
-#elif defined(OS_FUCHSIA)
+#elif defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
