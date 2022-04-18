$NetBSD: patch-src_3rdparty_chromium_components_viz_common_features.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/viz/common/features.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/viz/common/features.cc
@@ -21,7 +21,7 @@ const base::Feature kForcePreferredInter
     "ForcePreferredIntervalForVideo", base::FEATURE_DISABLED_BY_DEFAULT};
 
 // Use the SkiaRenderer.
-#if defined(OS_WIN) || \
+#if defined(OS_WIN) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST)))
 const base::Feature kUseSkiaRenderer{"UseSkiaRenderer",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
