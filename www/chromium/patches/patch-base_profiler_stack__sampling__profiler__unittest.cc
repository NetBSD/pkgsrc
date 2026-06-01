$NetBSD: patch-base_profiler_stack__sampling__profiler__unittest.cc,v 1.20 2026/06/01 10:09:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -46,7 +46,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
