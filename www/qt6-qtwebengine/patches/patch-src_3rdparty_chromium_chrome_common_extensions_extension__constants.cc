$NetBSD: patch-src_3rdparty_chromium_chrome_common_extensions_extension__constants.cc,v 1.1 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/extensions/extension_constants.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/extensions/extension_constants.cc
@@ -38,7 +38,7 @@ const char* const kBuiltInFirstPartyExte
     kGoogleSpeechSynthesisExtensionId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
     kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     kTTSEngineExtensionId,
     kComponentUpdaterTTSEngineExtensionId,
 #endif        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
