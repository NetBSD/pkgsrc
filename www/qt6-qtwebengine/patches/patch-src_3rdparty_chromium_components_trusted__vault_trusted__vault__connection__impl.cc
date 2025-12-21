$NetBSD: patch-src_3rdparty_chromium_components_trusted__vault_trusted__vault__connection__impl.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/trusted_vault/trusted_vault_connection_impl.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/components/trusted_vault/trusted_vault_connection_impl.cc
@@ -102,7 +102,7 @@ GetLocalPhysicalDeviceType() {
   // currently used or even built on all platforms.
 #if BUILDFLAG(IS_CHROMEOS)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_CHROMEOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_ANDROID;
