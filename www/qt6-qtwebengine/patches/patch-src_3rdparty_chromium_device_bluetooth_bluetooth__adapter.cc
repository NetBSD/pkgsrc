$NetBSD: patch-src_3rdparty_chromium_device_bluetooth_bluetooth__adapter.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc
@@ -32,7 +32,7 @@ namespace device {
 BluetoothAdapter::ServiceOptions::ServiceOptions() = default;
 BluetoothAdapter::ServiceOptions::~ServiceOptions() = default;
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && \
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
 // static
 scoped_refptr<BluetoothAdapter> BluetoothAdapter::CreateAdapter() {
