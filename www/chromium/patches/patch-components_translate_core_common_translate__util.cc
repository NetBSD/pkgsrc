$NetBSD: patch-components_translate_core_common_translate__util.cc,v 1.33 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/translate/core/common/translate_util.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/translate/core/common/translate_util.cc
@@ -44,7 +44,7 @@ bool IsTFLiteLanguageDetectionEnabled() 
 // The feature is explicitly disabled on WebView.
 // TODO(crbug.com/40819484): Enable the feature on WebView.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
