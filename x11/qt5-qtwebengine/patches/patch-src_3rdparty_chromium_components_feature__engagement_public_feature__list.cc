$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__list.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_list.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_list.cc
@@ -67,7 +67,7 @@ const base::Feature* const kAllFeatures[
     &kIPHDiscoverFeedHeaderFeature,
 #endif  // defined(OS_IOS)
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusModeFeature,
     &kIPHGlobalMediaControlsFeature,
