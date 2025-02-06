$NetBSD: patch-base_process_process__metrics__posix.cc,v 1.1 2025/02/06 09:57:42 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/process/process_metrics_posix.cc
@@ -21,6 +21,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -134,7 +136,7 @@ size_t ProcessMetrics::GetMallocUsage() 
   return stats.size_in_use;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   return GetMallocUsageMallinfo();
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
