$NetBSD: patch-chrome_common_extensions_extension__constants.h,v 1.31 2026/11/08 15:38:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/extension_constants.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/common/extensions/extension_constants.h
@@ -197,7 +197,7 @@ enum AppLaunchBucket {
 inline constexpr base::FilePath::CharType kAimEligibilityExtensionDirName[] =
     FILE_PATH_LITERAL("aim_eligibility_extension");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
@@ -247,7 +247,7 @@ inline constexpr auto kBuiltInFirstParty
         kEspeakSpeechSynthesisExtensionId,
         kGoogleSpeechSynthesisExtensionId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
         kTTSEngineExtensionId,
         kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
