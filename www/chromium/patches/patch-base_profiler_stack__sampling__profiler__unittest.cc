$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.15 2026/02/15 09:03:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -46,7 +46,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
