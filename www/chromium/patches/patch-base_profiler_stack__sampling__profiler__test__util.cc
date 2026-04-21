$NetBSD: patch-base_profiler_stack__sampling__profiler__test__util.cc,v 1.18 2026/04/21 15:21:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -46,7 +46,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
