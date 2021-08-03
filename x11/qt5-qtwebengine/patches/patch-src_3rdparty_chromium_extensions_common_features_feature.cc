$NetBSD: patch-src_3rdparty_chromium_extensions_common_features_feature.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/common/features/feature.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/common/features/feature.cc
@@ -20,7 +20,7 @@ namespace extensions {
 Feature::Platform Feature::GetCurrentPlatform() {
 #if defined(OS_CHROMEOS)
   return CHROMEOS_PLATFORM;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return LINUX_PLATFORM;
 #elif defined(OS_MACOSX)
   return MACOSX_PLATFORM;
