$NetBSD: patch-v8_src_diagnostics_perf-jit.cc,v 1.6 2025/09/08 13:24:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/diagnostics/perf-jit.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ v8/src/diagnostics/perf-jit.cc
@@ -31,7 +31,7 @@
 #include "src/flags/flags.h"
 
 // Only compile the {PerfJitLogger} on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
 
 #include <fcntl.h>
 #include <sys/mman.h>
