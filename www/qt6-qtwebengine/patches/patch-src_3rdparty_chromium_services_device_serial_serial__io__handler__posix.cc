$NetBSD: patch-src_3rdparty_chromium_services_device_serial_serial__io__handler__posix.cc,v 1.1 2025/12/21 09:38:37 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc
@@ -73,7 +73,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
