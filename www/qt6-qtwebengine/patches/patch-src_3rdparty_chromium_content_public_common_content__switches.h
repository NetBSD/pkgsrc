$NetBSD: patch-src_3rdparty_chromium_content_public_common_content__switches.h,v 1.1 2025/12/21 09:38:28 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -108,6 +108,7 @@ CONTENT_EXPORT extern const char kEnable
 CONTENT_EXPORT extern const char kEnableIsolatedWebAppsInRenderer[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -264,7 +265,7 @@ CONTENT_EXPORT extern const char kRender
 CONTENT_EXPORT extern const char kPreventResizingContentsForTesting[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
