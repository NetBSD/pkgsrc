$NetBSD: patch-chrome_browser_extensions_component__extensions__allowlist_allowlist.cc,v 1.2 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -48,7 +48,7 @@ bool IsComponentExtensionAllowlisted(con
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
       extension_misc::kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -85,7 +85,7 @@ bool IsComponentExtensionAllowlisted(int
     case IDR_NETWORK_SPEECH_SYNTHESIS_MANIFEST:
     case IDR_NETWORK_SPEECH_SYNTHESIS_MANIFEST_MV3:
     case IDR_READING_MODE_GDOCS_HELPER_MANIFEST:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDR_TTS_ENGINE_MANIFEST:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
     case IDR_WEBSTORE_MANIFEST:
