$NetBSD: patch-chrome_common_extensions_extension__constants.h,v 1.22 2026/07/08 13:42:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/extension_constants.h.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/common/extensions/extension_constants.h
@@ -329,7 +329,7 @@ inline constexpr char kReadingModeGDocsH
 inline constexpr base::FilePath::CharType
     kReadingModeGDocsHelperManifestFilename[] =
         FILE_PATH_LITERAL("reading_mode_gdocs_helper_manifest.json");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
@@ -380,7 +380,7 @@ inline constexpr auto kBuiltInFirstParty
         kGoogleSpeechSynthesisExtensionId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
         kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
         kTTSEngineExtensionId,
         kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
