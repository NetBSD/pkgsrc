$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -47,7 +47,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
