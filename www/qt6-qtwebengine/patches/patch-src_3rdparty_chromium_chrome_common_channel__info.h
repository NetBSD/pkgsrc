$NetBSD: patch-src_3rdparty_chromium_chrome_common_channel__info.h,v 1.2 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/channel_info.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/channel_info.h
@@ -11,7 +11,7 @@
 #include "build/branding_buildflags.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace base {
 class Environment;
 }
@@ -99,7 +99,7 @@ void ClearChannelIdForTesting();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName();
 
 // Returns the channel-specific filename of the desktop shortcut used to launch
