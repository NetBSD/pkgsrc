$NetBSD: patch-extensions_common_features_feature.cc,v 1.33 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/features/feature.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ extensions/common/features/feature.cc
@@ -29,6 +29,8 @@ Feature::Platform Feature::GetCurrentPla
   return WIN_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
