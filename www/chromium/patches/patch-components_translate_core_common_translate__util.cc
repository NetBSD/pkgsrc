$NetBSD: patch-components_translate_core_common_translate__util.cc,v 1.4 2025/07/25 16:17:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/translate/core/common/translate_util.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/translate/core/common/translate_util.cc
@@ -21,7 +21,7 @@ const char kSecurityOrigin[] = "https://
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
              "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
