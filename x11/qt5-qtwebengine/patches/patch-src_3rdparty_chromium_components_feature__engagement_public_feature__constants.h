$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -17,7 +17,7 @@ extern const base::Feature kIPHDemoMode;
 extern const base::Feature kIPHDummyFeature;
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusModeFeature;
 extern const base::Feature kIPHGlobalMediaControlsFeature;
