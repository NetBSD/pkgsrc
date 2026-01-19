$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -46,7 +46,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
