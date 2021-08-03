$NetBSD: patch-src_3rdparty_chromium_base_base__switches.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/base_switches.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -117,7 +117,7 @@ const char kDisableHighResTimer[] = "dis
 const char kDisableUsbKeyboardDetect[]      = "disable-usb-keyboard-detect";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
@@ -138,7 +138,7 @@ const char kEnableCrashReporterForTestin
 const char kEnableReachedCodeProfiler[] = "enable-reached-code-profiler";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether or not retired instruction counts are surfaced for threads
 // in trace events on Linux.
 //
