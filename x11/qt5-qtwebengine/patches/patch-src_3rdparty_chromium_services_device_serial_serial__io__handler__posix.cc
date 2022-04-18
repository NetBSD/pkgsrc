$NetBSD: patch-src_3rdparty_chromium_services_device_serial_serial__io__handler__posix.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc
@@ -67,7 +67,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
