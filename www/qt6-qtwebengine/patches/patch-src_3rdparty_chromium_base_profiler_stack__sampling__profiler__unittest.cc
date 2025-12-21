$NetBSD: patch-src_3rdparty_chromium_base_profiler_stack__sampling__profiler__unittest.cc,v 1.1 2025/12/21 09:38:15 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc
@@ -45,7 +45,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
