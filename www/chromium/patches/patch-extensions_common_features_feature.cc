$NetBSD: patch-extensions_common_features_feature.cc,v 1.5 2025/08/13 07:44:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/common/features/feature.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ extensions/common/features/feature.cc
@@ -32,6 +32,8 @@ Feature::Platform Feature::GetCurrentPla
   return FUCHSIA_PLATFORM;
 #elif BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
   return DESKTOP_ANDROID_PLATFORM;
+#elif BUILDFLAG(IS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
