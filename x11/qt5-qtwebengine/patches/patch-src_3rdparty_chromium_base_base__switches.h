$NetBSD: patch-src_3rdparty_chromium_base_base__switches.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/base_switches.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.h
@@ -39,7 +39,7 @@ extern const char kDisableHighResTimer[]
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -55,7 +55,7 @@ extern const char kEnableIdleTracing[];
 extern const char kForceFieldTrialParams[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
