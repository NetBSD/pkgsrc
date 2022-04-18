$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__list.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_list.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_list.h
@@ -127,7 +127,7 @@ DEFINE_VARIATION_PARAM(kIPHDiscoverFeedH
 #endif  // defined(OS_IOS)
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
 DEFINE_VARIATION_PARAM(kIPHFocusModeFeature, "IPH_FocusMode");
@@ -197,7 +197,7 @@ constexpr flags_ui::FeatureEntry::Featur
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
         VARIATION_ENTRY(kIPHDiscoverFeedHeaderFeature),
 #elif defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
         VARIATION_ENTRY(kIPHGlobalMediaControls),
