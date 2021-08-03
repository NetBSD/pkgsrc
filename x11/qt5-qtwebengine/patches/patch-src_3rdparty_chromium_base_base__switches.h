$NetBSD: patch-src_3rdparty_chromium_base_base__switches.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/base_switches.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.h
@@ -38,7 +38,7 @@ extern const char kDisableHighResTimer[]
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -51,7 +51,7 @@ extern const char kEnableReachedCodeProf
 extern const char kOrderfileMemoryOptimization[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
