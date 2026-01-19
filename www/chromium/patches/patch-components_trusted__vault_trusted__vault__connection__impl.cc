$NetBSD: patch-components_trusted__vault_trusted__vault__connection__impl.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/trusted_vault/trusted_vault_connection_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/trusted_vault/trusted_vault_connection_impl.cc
@@ -105,7 +105,7 @@ GetLocalPhysicalDeviceType() {
   // currently used or even built on all platforms.
 #if BUILDFLAG(IS_CHROMEOS)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_CHROMEOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_ANDROID;
