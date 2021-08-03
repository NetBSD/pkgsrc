$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__list.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_list.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_list.cc
@@ -59,7 +59,7 @@ const base::Feature* const kAllFeatures[
     &kIPHBadgedTranslateManualTriggerFeature,
 #endif  // defined(OS_IOS)
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     &kIPHFocusModeFeature,
     &kIPHGlobalMediaControlsFeature,
     &kIPHReopenTabFeature,
