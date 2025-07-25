$NetBSD: patch-services_device_serial_serial__io__handler__posix.cc,v 1.4 2025/07/25 16:17:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/serial/serial_io_handler_posix.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ services/device/serial/serial_io_handler_posix.cc
@@ -73,7 +73,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
