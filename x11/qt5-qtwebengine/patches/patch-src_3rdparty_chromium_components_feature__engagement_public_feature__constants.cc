$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc
@@ -13,7 +13,7 @@ const base::Feature kIPHDummyFeature{"IP
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kIPHDesktopTabGroupsNewGroupFeature{
     "IPH_DesktopTabGroupsNewGroup", base::FEATURE_DISABLED_BY_DEFAULT};
 const base::Feature kIPHFocusModeFeature{"IPH_FocusMode",
