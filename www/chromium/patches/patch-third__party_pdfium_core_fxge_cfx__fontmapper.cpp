$NetBSD: patch-third__party_pdfium_core_fxge_cfx__fontmapper.cpp,v 1.17 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -157,7 +157,7 @@ constexpr AltFontFamily kAltFontFamilies
     {"ForteMT", "Forte"},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif BUILDFLAG(IS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";
