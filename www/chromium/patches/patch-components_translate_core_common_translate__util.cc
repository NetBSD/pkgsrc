$NetBSD: patch-components_translate_core_common_translate__util.cc,v 1.15 2026/02/15 09:04:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/translate/core/common/translate_util.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/translate/core/common/translate_util.cc
@@ -29,7 +29,7 @@ bool IsTFLiteLanguageDetectionEnabled() 
 // The feature is explicitly disabled on WebView.
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
