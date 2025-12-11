$NetBSD: patch-extensions_common_features_feature.cc,v 1.11 2025/12/11 09:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/features/feature.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ extensions/common/features/feature.cc
@@ -30,6 +30,8 @@ Feature::Platform Feature::GetCurrentPla
   return WIN_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
