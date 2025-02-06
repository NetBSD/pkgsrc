$NetBSD: patch-base_profiler_stack__sampling__profiler__test__util.cc,v 1.1 2025/02/06 09:57:42 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -42,7 +42,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
