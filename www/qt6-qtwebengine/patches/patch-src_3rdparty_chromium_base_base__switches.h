$NetBSD: patch-src_3rdparty_chromium_base_base__switches.h,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/base_switches.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.h
@@ -41,7 +41,7 @@ extern const char kDisableHighResTimer[]
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
