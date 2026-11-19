$NetBSD: patch-chrome_common_extensions_extension__constants.h,v 1.32 2026/11/19 19:45:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/extension_constants.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/common/extensions/extension_constants.h
@@ -175,7 +175,7 @@ inline constexpr base::FilePath::CharTyp
 inline constexpr base::FilePath::CharType kNewTabPageExtensionDirName[] =
     FILE_PATH_LITERAL("new_tab_page_extension");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
@@ -225,7 +225,7 @@ inline constexpr auto kBuiltInFirstParty
         kGoogleSpeechSynthesisExtensionId,
         kTextEditorAppId,
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
         kTTSEngineExtensionId,
         kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
