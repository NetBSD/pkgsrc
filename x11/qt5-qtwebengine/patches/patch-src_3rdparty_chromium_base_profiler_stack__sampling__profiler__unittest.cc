$NetBSD: patch-src_3rdparty_chromium_base_profiler_stack__sampling__profiler__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc.orig	2020-07-08 21:41:45.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc
@@ -41,7 +41,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif defined(OS_LINUX)
 #include <alloca.h>
 #endif
 
