$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.8 2025/10/16 19:43:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -47,7 +47,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
