$NetBSD: patch-src_3rdparty_chromium_v8_src_diagnostics_perf-jit.h,v 1.2 2026/04/30 06:39:46 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/diagnostics/perf-jit.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {PerfJitLogger} is only implemented on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
 
 #include "src/logging/log.h"
 
