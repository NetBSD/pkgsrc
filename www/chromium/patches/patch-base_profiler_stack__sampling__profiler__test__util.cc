$NetBSD: patch-base_profiler_stack__sampling__profiler__test__util.cc,v 1.11 2025/12/11 09:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -50,7 +50,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
