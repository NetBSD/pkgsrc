$NetBSD: patch-src_3rdparty_chromium_extensions_common_features_feature.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/extensions/common/features/feature.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/extensions/common/features/feature.cc
@@ -26,7 +26,7 @@ Feature::Platform Feature::GetCurrentPla
   return LACROS_PLATFORM;
 #elif defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
   return CHROMEOS_PLATFORM;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return LINUX_PLATFORM;
 #elif defined(OS_MAC)
   return MACOSX_PLATFORM;
