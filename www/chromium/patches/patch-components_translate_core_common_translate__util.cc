$NetBSD: patch-components_translate_core_common_translate__util.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/translate/core/common/translate_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/translate/core/common/translate_util.cc
@@ -19,7 +19,7 @@ const char kSecurityOrigin[] = "https://
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
