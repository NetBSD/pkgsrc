$NetBSD: patch-src_3rdparty_chromium_chrome_common_channel__info.h,v 1.1 2025/12/21 09:38:20 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/channel_info.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/channel_info.h
@@ -12,7 +12,7 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace base {
 class Environment;
 }
@@ -100,7 +100,7 @@ void ClearChannelIdForTesting();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName();
 
 // Returns the channel-specific filename of the desktop shortcut used to launch
