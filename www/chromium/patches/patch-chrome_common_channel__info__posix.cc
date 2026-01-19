$NetBSD: patch-chrome_common_channel__info__posix.cc,v 1.14 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/channel_info_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/common/channel_info_posix.cc
@@ -92,7 +92,7 @@ std::string GetChannelSuffixForDataDir()
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   const auto channel_state = GetChannelImpl();
@@ -117,7 +117,7 @@ std::string GetChannelSuffixForExtraFlag
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
