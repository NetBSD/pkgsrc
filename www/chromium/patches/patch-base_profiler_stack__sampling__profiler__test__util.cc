$NetBSD: patch-base_profiler_stack__sampling__profiler__test__util.cc,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -50,7 +50,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
