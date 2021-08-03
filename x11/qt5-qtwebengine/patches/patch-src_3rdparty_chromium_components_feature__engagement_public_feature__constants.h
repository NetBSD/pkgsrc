$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -18,7 +18,7 @@ extern const base::Feature kIPHDemoMode;
 extern const base::Feature kIPHDummyFeature;
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const base::Feature kIPHFocusModeFeature;
 extern const base::Feature kIPHGlobalMediaControlsFeature;
 extern const base::Feature kIPHReopenTabFeature;
