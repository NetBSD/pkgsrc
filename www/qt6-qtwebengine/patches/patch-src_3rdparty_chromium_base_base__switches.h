$NetBSD: patch-src_3rdparty_chromium_base_base__switches.h,v 1.2 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/base_switches.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.h
@@ -41,7 +41,7 @@ extern const char kDisableUsbKeyboardDet
 extern const char kForceHighResTimeTicks[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
