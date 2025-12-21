$NetBSD: patch-src_3rdparty_chromium_base_base__switches.cc,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/base_switches.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -133,7 +133,7 @@ const char kDisableHighResTimer[] = "dis
 const char kDisableUsbKeyboardDetect[] = "disable-usb-keyboard-detect";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
