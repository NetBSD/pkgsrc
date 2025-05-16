$NetBSD: patch-components_permissions_prediction__service_prediction__common.cc,v 1.2 2025/05/16 16:08:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/permissions/prediction_service/prediction_common.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/permissions/prediction_service/prediction_common.cc
@@ -34,7 +34,7 @@ int BucketizeValue(int count) {
 
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_DESKTOP;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_Platform_PLATFORM_MOBILE;
@@ -45,7 +45,7 @@ ClientFeatures_Platform GetCurrentPlatfo
 
 ClientFeatures_PlatformEnum GetCurrentPlatformEnumProto() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_DESKTOP_V2;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return permissions::ClientFeatures_PlatformEnum_PLATFORM_MOBILE_V2;
