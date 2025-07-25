$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.4 2025/07/25 16:17:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -47,7 +47,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
