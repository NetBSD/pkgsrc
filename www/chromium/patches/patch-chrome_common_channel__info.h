$NetBSD: patch-chrome_common_channel__info.h,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/channel_info.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/common/channel_info.h
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
