$NetBSD: patch-chrome_browser_extensions_component__extensions__allowlist_allowlist.cc,v 1.31 2026/11/08 15:38:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -55,7 +55,7 @@ bool IsComponentExtensionAllowlisted(con
       extension_misc::kQuickOfficeComponentExtensionId,
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
