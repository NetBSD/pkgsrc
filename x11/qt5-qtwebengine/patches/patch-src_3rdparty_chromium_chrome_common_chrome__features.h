$NetBSD: patch-src_3rdparty_chromium_chrome_common_chrome__features.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/chrome_features.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_features.h
@@ -82,7 +82,7 @@ extern const base::Feature kAppShimNewCl
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
