$NetBSD: patch-services_device_usb_usb__device__handle__usbfs.cc,v 1.13 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/usb/usb_device_handle_usbfs.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/device/usb/usb_device_handle_usbfs.cc
@@ -34,7 +34,7 @@
 #include "chromeos/dbus/permission_broker/permission_broker_client.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_macros.h"
 #include "services/device/public/cpp/device_features.h"
 #include "services/device/usb/usb_interface_detach_allowlist.h"
@@ -51,7 +51,7 @@ using mojom::UsbTransferType;
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Outcome of detaching a kernel driver before ClaimInterface().
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
@@ -293,7 +293,7 @@ bool UsbDeviceHandleUsbfs::BlockingTaskR
   return true;
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::DetachInterface(
     int interface_number,
     const CombinedInterfaceInfo& interface_info) {
@@ -630,7 +630,7 @@ void UsbDeviceHandleUsbfs::ClaimInterfac
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     const mojom::UsbConfigurationInfo* config =
         device_->GetActiveConfiguration();
@@ -976,7 +976,7 @@ void UsbDeviceHandleUsbfs::ReleaseInterf
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     helper_.AsyncCall(&BlockingTaskRunnerHelper::ReattachInterface)
         .WithArgs(interface_number)
