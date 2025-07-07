$NetBSD: patch-chrome_common_extensions_extension__constants.cc,v 1.2 2025/07/07 09:23:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/extension_constants.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/common/extensions/extension_constants.cc
@@ -38,7 +38,7 @@ const char* const kBuiltInFirstPartyExte
     kGoogleSpeechSynthesisExtensionId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
     kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     kTTSEngineExtensionId,
     kComponentUpdaterTTSEngineExtensionId,
 #endif        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
