$NetBSD: patch-extensions_common_features_feature.cc,v 1.26 2026/09/22 13:41:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/features/feature.cc.orig	2026-09-14 22:17:16.000000000 +0000
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
